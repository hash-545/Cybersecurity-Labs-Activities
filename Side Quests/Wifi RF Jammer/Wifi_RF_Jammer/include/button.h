#pragma once

// Initialise button pins as input with internal pull-up
void button_init();

// FreeRTOS task — polls start/stop buttons and updates jamming state
void button_task(void* params);
