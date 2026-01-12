# Mixed-Signal Guitar Effects Pedal

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Status](https://img.shields.io/badge/status-In%20Development-yellow.svg)
![PCB](https://img.shields.io/badge/PCB-4--layer-green.svg)

A standalone programmable guitar effects pedal implemented on a custom mixed-signal embedded platform with real-time DSP processing on an STM32 microcontroller.

---

## Overview

This project is the end-to-end design and bring-up of a custom 4-layer mixed-signal embedded platform for real-time audio acquisition, digital signal processing, and playback. An external high-resolution ADC and DAC interface with an STM32 microcontroller to enable deterministic, low-latency audio processing in a standalone system operating without a host PC.

The analog front end provides a high-impedance guitar input stage, precision biasing, and a 3rd-order Butterworth anti-aliasing filter to condition signals prior to conversion. Reconstruction filtering and low-noise output buffering suppress imaging artifacts and maintain low distortion across the audible band. PCB layout emphasizes controlled return paths, analog–digital domain isolation, low-impedance grounding, and consistent impedance to minimize coupling between sensitive analog circuitry and high-speed digital switching.

Power delivery is implemented using a USB-C input feeding a multi-rail regulation architecture to support low-noise analog supplies and regulated digital rails. All power stages and filter networks were simulated and validated in LTspice prior to layout. Decoupling and bypass networks were optimized per device requirements to ensure supply stability under dynamic load conditions.

Firmware is developed bare-metal in STM32CubeIDE using timer-triggered ADC sampling, DMA-based double buffering, and deterministic interrupt scheduling. Digital signal processing algorithms—including soft-clipping distortion, equalization, and filtering—are implemented in C using the CMSIS-DSP library on a Cortex-M4 FPU platform. The system targets a 48 kHz sample rate with sub-5 ms end-to-end latency to preserve instrument responsiveness.

The platform serves as a practical environment for developing embedded firmware architecture, hardware–software co-design techniques, signal integrity practices, and real-time performance analysis while producing a functional guitar effects processor from schematic to working prototype.

---

## Key Objectives

- Design and validate a professional-grade mixed-signal PCB for low-noise audio applications  
- Implement deterministic real-time audio processing on embedded hardware  
- Develop practical experience with ADC/DAC interfacing, buffering, and latency management  
- Integrate hardware bring-up, firmware development, and signal characterization into a complete system  

---

## Features

### Hardware
- STM32 microcontroller with floating-point acceleration  
- External high-resolution ADC and DAC for audio conversion  
- 4-layer PCB optimized for signal integrity and power integrity  
- 3rd-order Butterworth analog anti-aliasing filter  
- USB-C powered multi-rail regulation architecture  

### DSP
- Bare-metal real-time audio pipeline  
- DMA-based double buffering  
- Soft-clipping distortion processing  
- Digital equalization and filtering  
- Deterministic sampling and low-latency operation  

---

## Technical Stack

### Hardware
- STM32 Microcontroller (ARM Cortex-M4 with FPU)  
- External high-resolution ADC and DAC  
- 4-layer PCB with controlled impedance and solid reference planes  
- USB-C power delivery and multi-rail regulation  

### Software & Tools
- KiCad – Schematic capture and PCB layout  
- STM32CubeIDE – Bare-metal firmware development  
- CMSIS-DSP – Optimized DSP library  
- LTspice – Circuit simulation and filter verification  
- C/C++ – Embedded firmware implementation  

---

## Design Process

### Circuit Design & Simulation
Analog input and output stages were designed for guitar signal conditioning, biasing, and bandwidth control. A 3rd-order Butterworth anti-aliasing filter was simulated and verified in LTspice along with ADC/DAC interfacing and power regulation networks.

### PCB Layout (4-Layer Stack-Up)

- **Layer 1:** Top signal layer (components, sensitive analog routing, high-speed digital signals)  
- **Layer 2:** Solid ground plane for low-impedance return paths and noise control  
- **Layer 3:** Secondary reference plane for shielding and analog/digital isolation  
- **Layer 4:** Bottom signal layer for routing and power distribution  

**Design considerations include:**
- Analog and digital domain isolation  
- Controlled impedance routing for high-speed signals  
- Low-inductance return paths and continuous reference planes  
- Robust decoupling and power integrity practices  

### Firmware Architecture

Firmware configures ADC, DAC, timers, DMA, and interrupt scheduling to form a deterministic real-time audio pipeline. Audio samples are acquired using timer-triggered ADC conversions, buffered via DMA, processed in interrupt callbacks, and streamed to the DAC with minimal jitter and latency.

DSP algorithms are implemented in C using CMSIS-DSP primitives and floating-point arithmetic to accelerate development and maintain numerical stability.

---

## Development Status

### Completed
- Schematic design and circuit simulation  
- 3rd-order Butterworth filter design and verification  
- 4-layer PCB layout and stack-up definition  
- Component selection and BOM creation  

### In Progress
- Bare-metal firmware development  
- Real-time DSP implementation  
- PCB fabrication and assembly  

### Planned
- Hardware bring-up and validation  
- Audio performance measurement and characterization  
- Enclosure design and mechanical integration  
- Additional DSP effects (chorus, delay, reverb)  

---

## Technical Specifications

### Audio Path
- Input Impedance: 1 MΩ  
- Sample Rate: 48 kHz  
- Bit Depth: 16–24 bit (ADC dependent)  
- Frequency Response: 20 Hz – 20 kHz  
- Anti-Aliasing Filter: 3rd-order Butterworth, fc ≈ 20 kHz  

### Power
- Input: USB-C (5 V)  
- Internal Rails: 3.3 V (digital), ±5 V or +9 V (analog)  
- Estimated Current Consumption: 200–300 mA  

### Processing
- MCU: STM32 ARM Cortex-M4 with FPU  
- Target End-to-End Latency: < 5 ms  

---

## Engineering Focus

This project provides hands-on experience in:

- Mixed-signal PCB design and layout techniques  
- Real-time embedded firmware development  
- DMA-based buffering and interrupt-driven architectures  
- Analog signal conditioning and filter design  
- Audio signal processing fundamentals  
- Hardware bring-up and debugging on custom PCBs  
- Hardware–software co-design tradeoffs  

---

## Roadmap

### Phase 1 — Core Development (Current)
- Complete DSP firmware implementation  
- Fabricate and assemble PCB  
- Initial bring-up and debugging  

### Phase 2 — Refinement
- Audio performance characterization  
- Latency and CPU utilization optimization  
- PCB revision based on test results  

### Phase 3 — Enhancement
- Additional DSP effects  
- USB parameter control interface  
- Enclosure design and fabrication  

---

## References

### DSP
- *The Scientist and Engineer's Guide to Digital Signal Processing* — Steven W. Smith  
- *Understanding Digital Signal Processing* — Richard G. Lyons  
- *Small Signal Audio Design* — Douglas Self  

### Application Notes
- STM32 Audio Processing Application Notes  
- High-Speed PCB Design Guidelines  
- Audio ADC/DAC Interface Best Practices  

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Contact

**Daniel Romero**  
Email: daniel.romero@ieee.org  
Portfolio: https://electricalromero.com  
LinkedIn: https://www.linkedin.com/in/daniel-romero-ee/  

---

_Last updated: January 2026_
