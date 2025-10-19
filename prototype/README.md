# Prototype Pattern: Button Cloning Example

This C++ example demonstrates the **Prototype Design Pattern**, which clones objects instead of creating them from scratch.

## Overview

The program defines an abstract `Button` class with a `clone()` method for cloning objects. Two concrete classes, `RedButton` and `BlueButton`, implement `clone()` to return new instances of their respective types. The buttons are rendered and then properly cleaned up.

## Classes

- **`Button`**: Abstract class with virtual `clone()` and `render()` methods.
- **`RedButton`**: A concrete button that clones itself and renders a "Red Button".
- **`BlueButton`**: A concrete button that clones itself and renders a "Blue Button".