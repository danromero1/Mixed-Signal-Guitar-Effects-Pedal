# PCB Stackup

This board uses a 4-layer stackup optimized for mixed-signal audio processing and embedded digital systems.

## Layer Configuration

| Layer | Name        | Function |
|------:|-------------|----------|
| L1    | Top (F.Cu)  | Signal routing and component placement |
| L2    | Inner 1     | Solid ground plane |
| L3    | Inner 2     | Solid ground plane |
| L4    | Bottom (B.Cu) | Secondary signal routing and low-speed interconnects |

## Design Rationale

- Dual internal ground planes provide low-inductance return paths for both analog and digital signals.
- Continuous, unbroken ground planes minimize EMI, ground bounce, and noise coupling in mixed-signal paths.
- Analog and digital circuits reference the same ground system to avoid return-path discontinuities.
- Critical signal routing is kept on the top layer with immediate reference to the adjacent ground plane.
- Bottom layer routing is used primarily for non-critical signals and escape routing.

## Mixed-Signal Considerations

- No split ground planes are used to prevent unintended return path interruptions.
- Stitching vias are placed near layer transitions to maintain return path continuity.
- Power and signal routing are arranged to minimize coupling between high-speed digital and sensitive analog sections.

## Notes

- Stackup prioritizes signal integrity and noise performance over routing density.
- Layout decisions follow standard mixed-signal PCB design best practices.
