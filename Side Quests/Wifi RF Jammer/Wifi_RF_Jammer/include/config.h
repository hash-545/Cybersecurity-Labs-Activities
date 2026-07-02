#pragma once

// ── Pin definitions ───────────────────────────────────────────────────────────
#define PIN_BTN_START   4
#define PIN_BTN_STOP    5
#define PIN_LED_RED     6
#define PIN_LED_GREEN   7

// ── Jammer config ─────────────────────────────────────────────────────────────
#define DWELL_MS        500     // ms to jam each channel per cycle
#define BURST_SIZE      200     // frames injected per burst
#define BLINK_FAST_MS   100     // LED blink interval in ms
#define CHANNEL_COUNT   3       // number of target channels