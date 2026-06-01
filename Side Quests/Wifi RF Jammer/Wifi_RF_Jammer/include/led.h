#pragma once

// Initialise LED pins as output
void led_init();

// FreeRTOS task — blinks red or green based on jamming state
void led_task(void* params);
