/**
 * button.cpp
 *
 * Polls two hardware buttons and updates the shared jamming flag accordingly.
 *
 * Buttons are wired active LOW — pressing connects the GPIO pin to GND.
 * The internal pull-up resistor holds the pin HIGH when the button is open,
 * so a LOW reading unambiguously means the button is pressed. This is the
 * standard wiring pattern for digital inputs on microcontrollers — it avoids
 * floating pin states that cause false triggers.
 *
 * Debounce is handled with a 200ms delay after detecting a press. Mechanical
 * buttons bounce — the contact opens and closes rapidly for a few milliseconds
 * on each press, producing multiple LOW readings from a single physical press.
 * Without debounce, one press would toggle the jamming state several times.
 */

#include "button.h"
#include "config.h"
#include "state.h"
#include "Arduino.h"

void button_init() {
    // INPUT_PULLUP enables the internal pull-up resistor — no external
    // resistor needed. Pin reads HIGH normally, LOW when button pressed.
    pinMode(PIN_BTN_START, INPUT_PULLUP);
    pinMode(PIN_BTN_STOP,  INPUT_PULLUP);
}

void button_task(void* params) {
    while (true) {
        if (digitalRead(PIN_BTN_START) == LOW) {
            if (jamming == false) {
                jamming = true;
                Serial.println("[*] Jamming STARTED");
            }
            // Debounce — ignore further input for 200ms after press
            vTaskDelay(200 / portTICK_PERIOD_MS);
        }

        if (digitalRead(PIN_BTN_STOP) == LOW) {
            if (jamming == true) {
                jamming = false;
                Serial.println("[*] Jamming STOPPED");
            }
            vTaskDelay(200 / portTICK_PERIOD_MS);
        }

        // Poll interval — 50ms is responsive enough for a button press
        // without burning CPU cycles checking constantly
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}