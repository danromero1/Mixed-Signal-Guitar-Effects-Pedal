# Mixed-Signal Guitar Effects Pedal

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Status](https://img.shields.io/badge/status-In%20Development-yellow.svg)
![PCB](https://img.shields.io/badge/PCB-4--layer-green.svg)

A programmable guitar effects pedal using mixed-signal design with real-time DSP processing on an STM32 microcontroller.

---

## Overview

This project implements a 4-layer PCB design for a guitar effects pedal featuring external ADC/DAC interfacing with an STM32 microcontroller for real-time digital signal processing. The pedal includes multiple audio effects: anti-aliasing filtering, equalization, and soft-clipping distortion.

### Key Objectives
- Design a professional-grade mixed-signal PCB layout
- Implement real-time audio DSP algorithms on embedded hardware
- Develop practical skills in analog-to-digital conversion and signal conditioning
- Create a functional guitar effects processor from schematic to working prototype

---

## Features

**Hardware**
- Real-time DSP processing with STM32 microcontroller
- External ADC/DAC for high-quality audio conversion
- 4-layer PCB with proper signal integrity and power distribution
- 3rd-order Butterworth anti-aliasing filter
- USB-C power delivery

**DSP Effects**
- Anti-aliasing filtering
- Digital equalization
- Soft-clipping distortion
- Real-time audio buffering

---

## Technical Stack

**Hardware Design**
- STM32 Microcontroller (ARM Cortex-M series)
- External high-resolution ADC/DAC
- 4-layer PCB with controlled impedance
- USB-C power delivery circuit

**Software & Tools**
- KiCAD - PCB design and schematic capture
- STM32CubeIDE - Firmware development
- LTspice - Circuit simulation and filter design
- C/C++ - Embedded firmware programming

---

## Design Process

### Circuit Design & Simulation
Designed analog input/output stages for guitar signal conditioning. Simulated 3rd-order Butterworth anti-aliasing filter in LTspice and validated ADC/DAC interfacing circuits.

### PCB Layout (4-Layer Stack-up)
- **Layer 1:** Top signal layer (components, high-speed signals)
- **Layer 2:** Ground plane (noise reduction, return paths)
- **Layer 3:** Ground plane (additional shielding, signal isolation)
- **Layer 4:** Bottom signal layer (routing, power distribution)

**Design Considerations:**
- Analog/digital domain separation
- Controlled impedance traces for high-speed signals
- Star grounding for audio path
- Power supply decoupling and noise filtering

### Firmware Development
STM32 peripheral configuration (ADC, DAC, timers, DMA), real-time audio buffer management, and DSP algorithm implementation in C.

---

## Project Status

**Completed**
- Schematic design and circuit simulation
- 3rd-order Butterworth filter design and verification
- PCB layout (4-layer stackup)
- Component selection and BOM creation

**In Progress**
- Firmware development and DSP algorithm implementation
- PCB fabrication and assembly

**Planned**
- Hardware testing and validation
- Audio quality measurements and characterization
- Enclosure design
- Additional DSP effects (chorus, delay, reverb)

---

## Technical Specifications

**Audio Path**
- Input Impedance: 1MΩ (guitar-friendly)
- Sample Rate: 48 kHz
- Bit Depth: 16-24 bit
- Frequency Response: 20 Hz - 20 kHz
- Anti-aliasing Filter: 3rd-order Butterworth, fc = 20 kHz

**Power**
- Input: USB-C (5V)
- Internal Rails: +3.3V (digital), ±5V or +9V (analog)
- Current Consumption: ~200-300mA (estimated)

**Processing**
- MCU: STM32 (ARM Cortex-M4 with FPU)
- Processing Latency: Target <5ms

---

## Learning Objectives

This project serves as practical exploration of:
- Mixed-signal PCB design techniques
- Real-time embedded DSP programming
- Analog circuit design (filters, amplifiers, signal conditioning)
- Audio engineering fundamentals
- Professional PCB layout practices

---

## Roadmap

**Phase 1: Core Development** (Current)
- Complete firmware DSP implementation
- Fabricate and assemble PCB
- Initial testing and debugging

**Phase 2: Refinement**
- Audio quality characterization
- Performance optimization
- PCB revision based on testing feedback

**Phase 3: Enhancement**
- Additional DSP effects
- USB parameter control interface
- Enclosure design and fabrication

---

## References

**DSP Theory**
- *The Scientist and Engineer's Guide to Digital Signal Processing* by Steven W. Smith
- *Understanding Digital Signal Processing* by Richard G. Lyons

**Application Notes**
- STM32 Audio Processing Application Notes
- High-Speed PCB Design Guidelines
- Audio ADC/DAC Interface Best Practices

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Contact

**Daniel Romero**  
Email: daniel.romero@ieee.org  
Portfolio: [electricalromero.com](https://electricalromero.com)  
LinkedIn: [linkedin.com/in/daniel-romero-ee](https://www.linkedin.com/in/daniel-romero-ee/)

---

*Last Updated: December 2025*
