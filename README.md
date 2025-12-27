# Mixed-Signal Guitar Effects Pedal

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Status](https://img.shields.io/badge/status-In%20Development-yellow.svg)
![PCB](https://img.shields.io/badge/PCB-4--layer-green.svg)

> A programmable guitar effects pedal using mixed-signal design with real-time DSP processing

## 🎯 Project Overview

This project is a 4-layer PCB design for a programmable guitar effects pedal featuring external ADC/DAC interfacing with an STM32 microcontroller for real-time digital signal processing. The pedal implements multiple audio effects including anti-aliasing filtering, equalization, and soft-clipping distortion.

**Key Objectives:**
- Design a professional-grade mixed-signal PCB layout
- Implement real-time audio DSP algorithms on embedded hardware
- Develop practical skills in analog-to-digital conversion and signal conditioning
- Create a functional guitar effects processor from schematic to working prototype

## ✨ Features

- **Real-time DSP Processing**: STM32 microcontroller running custom audio processing algorithms
- **High-Quality Audio Path**: External ADC/DAC for superior audio conversion
- **Multiple Effects**: Anti-aliasing filter, equalization, soft-clipping distortion
- **4-Layer PCB Design**: Professional layout with proper signal integrity and power distribution
- **USB-C Power Delivery**: Modern, reliable power input
- **3rd-Order Butterworth Filter**: Analog anti-aliasing filter for clean signal conversion

## 🛠️ Tech Stack

**Hardware:**
- STM32 Microcontroller (ARM Cortex-M series)
- External ADC/DAC IC (high-resolution audio conversion)
- 3rd-Order Butterworth analog filter
- 4-layer PCB with controlled impedance
- USB-C power delivery circuit

**Software & Tools:**
- **KiCAD**: PCB design and schematic capture
- **STM32CubeIDE**: Firmware development environment
- **LTspice**: Circuit simulation and filter design
- **C/C++**: Embedded firmware programming

**DSP Algorithms:**
- Anti-aliasing filtering
- Digital equalization
- Soft-clipping distortion
- Real-time audio buffering and processing

## 📐 Design Process

### 1. Circuit Design & Simulation
- Designed analog input/output stages for guitar signal conditioning
- Simulated 3rd-order Butterworth anti-aliasing filter in LTspice
- Validated ADC/DAC interfacing and power supply circuits

### 2. PCB Layout (4-Layer Stack-up)
- **Layer 1**: Top signal layer (components, high-speed signals)
- **Layer 2**: Ground plane (noise reduction, return paths)
- **Layer 3**: Power plane (+3.3V, +5V distribution)
- **Layer 4**: Bottom signal layer (routing, additional grounds)

Design considerations:
- Proper analog/digital domain separation
- Controlled impedance traces for high-speed signals
- Star grounding for audio path
- Power supply decoupling and noise filtering

### 3. Firmware Development
- STM32 peripheral configuration (ADC, DAC, timers, DMA)
- Real-time audio buffer management
- DSP algorithm implementation in C
- USB communication for parameter control (future enhancement)

## 🔧 Current Status

**Completed:**
- ✅ Schematic design and circuit simulation
- ✅ 3rd-order Butterworth filter design and verification
- ✅ PCB layout (4-layer stackup)
- ✅ Component selection and BOM creation

**In Progress:**
- 🔄 Firmware development and DSP algorithm implementation
- 🔄 PCB fabrication and assembly

**Planned:**
- 📋 Hardware testing and validation
- 📋 Audio quality measurements and characterization
- 📋 Enclosure design
- 📋 Additional DSP effects (chorus, delay, reverb)

## 📚 Technical Specifications

**Audio Path:**
- Input Impedance: 1MΩ (guitar-friendly)
- Sample Rate: 48 kHz
- Bit Depth: 16-24 bit (depending on ADC/DAC selection)
- Frequency Response: 20 Hz - 20 kHz
- Anti-aliasing Filter: 3rd-order Butterworth, fc = 20 kHz

**Power:**
- Input: USB-C (5V)
- Internal Rails: +3.3V (digital), ±5V or +9V (analog, depending on final design)
- Current Consumption: TBD (estimate ~200-300mA)

**Processing:**
- MCU: STM32 (ARM Cortex-M4 with FPU preferred for DSP operations)
- Processing Latency: Target <5ms (acceptable for guitar effects)

## 🎓 Learning Objectives

This project serves as a practical exploration of:
- Mixed-signal PCB design techniques
- Real-time embedded DSP programming
- Analog circuit design (filters, amplifiers, signal conditioning)
- Audio engineering fundamentals
- Professional PCB layout practices (layer stackup, impedance control, EMI mitigation)

## 🗺️ Roadmap

**Phase 1: Core Development** (Current)
- Complete firmware DSP implementation
- Fabricate and assemble PCB
- Initial testing and debugging

**Phase 2: Refinement**
- Audio quality characterization
- Performance optimization
- PCB revision based on testing feedback

**Phase 3: Enhancement**
- Add additional DSP effects
- Implement USB parameter control interface
- Design and fabricate enclosure
- Create user documentation

## 📖 Resources & References

**DSP Theory:**
- *The Scientist and Engineer's Guide to Digital Signal Processing* by Steven W. Smith
- *Understanding Digital Signal Processing* by Richard G. Lyons

**Application Notes:**
- STM32 Audio Processing Application Notes
- High-Speed PCB Design Guidelines
- Audio ADC/DAC Interface Best Practices

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📧 Contact

Daniel Romero - [daniel.romero@ieee.org](mailto:daniel.romero@ieee.org)

Portfolio: [electricalromero.com](https://electricalromero.com)

LinkedIn: [linkedin.com/in/daniel-romero-ee](https://www.linkedin.com/in/daniel-romero-ee/)

---

## 🙏 Acknowledgments

- DSP coursework and textbooks for theoretical foundation
- STMicroelectronics application notes and reference designs
- Online audio engineering and embedded systems communities

---

**Project Status**: Active Development | Last Updated: December 2024
