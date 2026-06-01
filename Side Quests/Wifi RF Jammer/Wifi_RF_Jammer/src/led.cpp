#include "led.h"
#include "config.h"
#include "state.h"
#include "Arduino.h"

void led_init() {
    pinMode(PIN_LED_RED,   OUTPUT);
    pinMode(PIN_LED_GREEN, OUTPUT);
    digitalWrite(PIN_LED_RED,   LOW);
    digitalWrite(PIN_LED_GREEN, LOW);
}

void led_task(void* params) {
    bool led_state = false;

    while (true) {
        if (jamming == true) {
            // Red blinks fast — green off
            digitalWrite(PIN_LED_GREEN, LOW);

            if (led_state == false) {
                digitalWrite(PIN_LED_RED, HIGH);
            } else {
                digitalWrite(PIN_LED_RED, LOW);
            }
        } else {
            // Green blinks fast — red off
            digitalWrite(PIN_LED_RED, LOW);

            if (led_state == false) {
                digitalWrite(PIN_LED_GREEN, HIGH);
            } else {
                digitalWrite(PIN_LED_GREEN, LOW);
            }
        }

        if (led_state == false) {
            led_state = true;
        } else {
            led_state = false;
        }

        vTaskDelay(BLINK_FAST_MS / portTICK_PERIOD_MS);
    }
}
