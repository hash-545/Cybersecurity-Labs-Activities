#include "Arduino.h"
#include "config.h"
#include "state.h"
#include "wifi_jammer.h"
#include "button.h"
#include "led.h"

void setup() {
    Serial.begin(115200);
    Serial.println("[*] ESP32-S3 Sweep Jammer starting");

    wifi_init();
    button_init();
    led_init();

    // Launch tasks on core 1 — core 0 handles Wi-Fi internals
    xTaskCreatePinnedToCore(sweep_task,  "sweep",   4096, NULL, 5, NULL, 1);
    xTaskCreatePinnedToCore(button_task, "buttons", 2048, NULL, 3, NULL, 1);
    xTaskCreatePinnedToCore(led_task,    "leds",    2048, NULL, 2, NULL, 1);
}

void loop() {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
