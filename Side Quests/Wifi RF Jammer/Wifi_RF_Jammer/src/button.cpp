#include "button.h"
#include "config.h"
#include "state.h"
#include "Arduino.h"

void button_init() {
    pinMode(PIN_BTN_START, INPUT_PULLUP);
    pinMode(PIN_BTN_STOP,  INPUT_PULLUP);
}

void button_task(void* params) {
    while (true) {
        // Start button pressed — active LOW
        if (digitalRead(PIN_BTN_START) == LOW) {
            if (jamming == false) {
                jamming = true;
                Serial.println("[*] Jamming STARTED");
            }
            vTaskDelay(200 / portTICK_PERIOD_MS);  // Debounce
        }

        // Stop button pressed — active LOW
        if (digitalRead(PIN_BTN_STOP) == LOW) {
            if (jamming == true) {
                jamming = false;
                Serial.println("[*] Jamming STOPPED");
            }
            vTaskDelay(200 / portTICK_PERIOD_MS);  // Debounce
        }

        vTaskDelay(50 / portTICK_PERIOD_MS);  // Poll every 50ms
    }
}