# ESP32-S3 Wi-Fi Sweep Jammer
**Status: Halted (hardware limitations)** 

---
## Disclaimer

This project was developed strictly for educational purposes as part of a personal wireless security research curriculum. All testing was conducted exclusively on infrastructure owned and controlled by the author.

**This tool must not be used to:**
- Jam, disrupt, or interfere with wireless communications not owned by you
- Target third-party networks, devices, or public infrastructure
- Cause denial of service to any individual, organisation, or service provider

Deliberate RF interference with third-party communications is illegal & prohibited under telecommunications law in all jurisdictions worldwide. Violations carry serious criminal penalties.

The author accepts no responsibility for misuse of this code. By using this project you accept full legal and ethical responsibility for your own actions.

This repository is intended for security professionals, researchers, and students conducting **authorised testing on their own infrastructure only**.


## Project Overview

A Wi-Fi channel saturation tool built on the ESP32-S3 as part of a structured RF and wireless cybersecurity curriculum. The goal was to demonstrate Layer 1 RF jamming via raw 802.11 frame injection, exploiting the CSMA/CA protocol to deny wireless communications in a controlled corporate lab environment.

---

## Knowledge Covered

### Theory
- RF fundamentals: frequency bands, channels, SNR, path loss, FSPL

- 2.4 GHz band occupants: Wi-Fi, Bluetooth, Zigbee, and their coexistence

- CSMA/CA: how the MAC layer controls medium access and how jamming exploits it

- 802.11 management frames: beacon, probe, auth, deauth, association
- 
- WPA2 weaknesses: unauthenticated management frames, handshake capture, PMKID

- WPA3 improvements: SAE, Dragonfly key exchange, forward secrecy, PMF

- Jamming taxonomy: spot, sweep, barrage, reactive, deauth-based DoS

- RRM: enterprise AP channel switching as a countermeasure and its limits

- Faraday cage effect: relevance to server racks and RF shielding

### Implementation
- ESP-IDF + Arduino framework coexistence on ESP32-S3

- FreeRTOS — tasks, scheduler, priorities, core pinning,  watchdog

- Raw 802.11 frame injection

- NVS initialisation requirements for the Wi-Fi driver

- Promiscuous mode as a prerequisite for raw injection on current SDK

---

## Project Structure

```
src/
├── main.cpp          — Entry point, task initialisation
├── wifi_jammer.cpp   — Frame injection and sweep logic
├── button.cpp        — Button polling task
├── led.cpp           — LED blink task
└── state.cpp         — Shared jamming flag
include/
├── config.h          — Pin definitions and tunable constants
├── wifi_jammer.h
├── button.h
├── led.h
└── state.h
```

---

## Hardware

| Component | Detail |
|---|---|
| MCU | ESP32-S3-DevKitM-1 |
| Start button | GPIO 4 — active LOW |
| Stop button | GPIO 5 — active LOW |
| Red LED | GPIO 6 — jamming indicator |
| Green LED | GPIO 7 — idle indicator |
| Resistors | 220Ω per LED |

---

## Why It Is Halted

### Root Cause — Insufficient TX Power

The ESP32-S3 at stock TX power (+21 dBm maximum) with a PCB trace antenna could not generate enough RF energy to measurably disrupt a router. Ping tests to both 8.8.8.8 and the router's local IP showed zero packet loss during active jamming.

### Contributing Factors

**No external antenna**: the ESP32-S3 variant used lacked an IPEX/U.FL connector, ruling out a 5 dBi external antenna without hardware modification.

**SDK raw injection limitations**: `esp_wifi_80211_tx()` returned error 257 (`ESP_ERR_INVALID_ARG`) until promiscuous mode was enabled. Even after resolution, the driver's internal queue limits sustained injection rate.

**Layer 1 vs Layer 2 distinction**: the ESP32 operates above the physical layer. True Layer 1 RF jamming requires SDR hardware (e.g. HackRF One) capable of generating arbitrary RF signals outside the 802.11 protocol stack. No software tool or standard Wi-Fi adapter can achieve this without hardware tweaks.

---

