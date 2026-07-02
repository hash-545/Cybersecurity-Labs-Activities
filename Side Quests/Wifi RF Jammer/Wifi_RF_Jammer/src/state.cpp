/**
 * state.cpp
 *
 * Defines the single instance of the shared jamming flag.
 *
 * Initialised to false so the device boots in a safe idle state —
 * jamming only begins when the start button is explicitly pressed.
 * This prevents accidental RF transmission on power-up.
 */

#include "state.h"

volatile bool jamming = false;