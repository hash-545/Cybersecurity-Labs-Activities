#pragma once

/**
 * state.h
 *
 * Single shared state flag accessed by three concurrent FreeRTOS tasks:
 * sweep_task (reads), button_task (writes), led_task (reads).
 *
 * Declared extern here so every file that includes this header references
 * the same single instance defined in state.cpp. Without extern, each
 * translation unit would get its own copy and tasks would never see each
 * other's updates.
 *
 * volatile forces the compiler to read the variable from memory on every
 * access rather than caching it in a CPU register. Without volatile, the
 * optimiser may assume the value cannot change between reads within the
 * same task and cache a stale value — meaning sweep_task could miss a
 * stop command from button_task entirely.
 */
extern volatile bool jamming;