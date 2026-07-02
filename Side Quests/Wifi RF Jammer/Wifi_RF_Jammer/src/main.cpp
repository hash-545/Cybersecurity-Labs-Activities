/**
 * main.cpp
 *
 * Entry point. Initialises all subsystems and launches three concurrent
 * FreeRTOS tasks — sweep, button polling, and LED control.
 *
 * All three tasks are pinned to core 1. The ESP32's Wi-Fi driver runs
 * its internal processing on core 0 — placing our tasks on core 1 keeps
 * them from competing with the Wi-Fi stack for CPU time, which would
 * cause frame injection delays and unstable radio behaviour.
 *
 * Task priorities are staggered:
 *   sweep_task  — priority 5 (highest) — frame injection must not be
 *                 interrupted mid-burst or the channel gaps let devices
 *                 through
 *   button_task — priority 3 — responsive enough at 50ms poll interval
 *   led_task    — priority 2 (lowest) — visual feedback, non-critical
 */

#include "Arduino.h"
#include "config.h"
#include "state.h"
#include "wifi_jammer.h"
#include "button.h"
#include "led.h"

void setup() {
    Serial.begin(115200);
    Serial.println("[*] ESP32-S3 Sweep Jammer starting");

    // Initialise Wi-Fi radio for raw frame injection
    wifi_init();

    // Initialise button and LED GPIO pins
    button_init();
    led_init();

    // Launch all tasks on core 1
    // Stack sizes: sweep needs more headroom for Wi-Fi API calls;
    // button and LED tasks are lightweight so 2048 bytes is sufficient
    xTaskCreatePinnedToCore(sweep_task,  "sweep",   4096, NULL, 5, NULL, 1);
    xTaskCreatePinnedToCore(button_task, "buttons", 2048, NULL, 3, NULL, 1);
    xTaskCreatePinnedToCore(led_task,    "leds",    2048, NULL, 2, NULL, 1);
}

void loop() {
    // All logic runs in FreeRTOS tasks — Arduino loop() is intentionally
    // idle. The delay yields control back to the scheduler rather than
    // burning core 1 CPU in a tight empty loop.
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}