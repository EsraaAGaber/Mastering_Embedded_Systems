# AVR Interrupts Project

This project demonstrates the use of external interrupts on an AVR microcontroller to control LEDs. The microcontroller responds to external interrupts by lighting up LEDs for a specified duration.

## Features

- **INT0 Interrupt**: Lights up LED connected to PORTD5.
- **INT1 Interrupt**: Lights up LED connected to PORTD6.
- **INT2 Interrupt**: Lights up LED connected to PORTD7.

## Components Used

- Atmel Studio (for development)
- Proteus (for simulation)

## Circuit Diagram

- Connect LEDs to PORTD5, PORTD6, and PORTD7.
- Connect push buttons to INT0 (PD2), INT1 (PD3), and INT2 (PB2).