# Electronic Component Factory

This project demonstrates the **Factory Method** design pattern to create and simulate different electronic components: **Resistor**, **Capacitor**, and **Transistor**.

## Features

- Defines an abstract `ElectronicComponent` class with `simulate()` and `type()` methods.
- Implements concrete classes for **Resistor**, **Capacitor**, and **Transistor**.
- Uses **Factory Method** pattern with factories:
  - `ResistorFactory`
  - `CapacitorFactory`
  - `TransistorFactory`