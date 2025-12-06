# 🎄 Christmas Tree Decorator Pattern

This C++ program demonstrates the **Decorator Design Pattern** through a simulation of decorating a Christmas tree. The program defines a basic tree structure and progressively adds various decorations (such as lights, ornaments, tinsel, and a star) to it, showcasing how the decorator pattern allows dynamic and flexible extensions of object behavior without modifying the core class.

## Decorator Pattern

The **Decorator Pattern** allows you to add behavior to an object dynamically without altering its structure. In this program, the `ChristmasTree` class serves as the base, and various decorators (`LightsDecorator`, `OrnamentsDecorator`, `TinselDecorator`, `StarDecorator`) modify the base tree to add extra functionality (decorations).

### Classes Overview

1. **`ChristmasTree` (Abstract Class)**
    - Defines the interface for decorating a Christmas tree with the `decorate()` method.

2. **`SimpleTree` (Concrete Class)**
    - Implements the basic `ChristmasTree` class and represents the base tree without any decorations.

3. **`TreeDecorator` (Abstract Decorator Class)**
    - A base decorator class that holds a reference to a `ChristmasTree` object and delegates the `decorate()` method to it.

4. **`LightsDecorator`, `OrnamentsDecorator`, `TinselDecorator`, `StarDecorator`**
    - Concrete decorator classes that add specific decorations (lights, ornaments, tinsel, and a star) to the tree.