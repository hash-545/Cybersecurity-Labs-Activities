#pragma once

// Initialise Wi-Fi radio for raw frame injection
void wifi_init();

// Inject burst of noise frames on a single channel
void jam_channel(uint8_t ch);

// FreeRTOS task — sweeps channels while jamming flag is true
void sweep_task(void* params);
