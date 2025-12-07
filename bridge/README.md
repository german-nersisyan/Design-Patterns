# 🐉 Creature Abilities with bridge pattern

This C++ program demonstrates the use of **polymorphism**, **inheritance**, and the **Bridge Design Pattern** to model different types of creatures with unique abilities. The creatures can perform various abilities such as fire breathing, healing, teleportation, and flight.

## Features

- Implements **polymorphism** using virtual functions to perform abilities.
- Uses **Strategy Design Pattern** to dynamically change the abilities of creatures.
- Utilizes **Bridge Design Pattern** to separate the abstraction of creatures from the implementation of abilities.
- Supports different creatures with distinct names and abilities:
  - `Dragon`: Breathes fire.
  - `Unicorn`: Heals allies.
  - `Phoenix`: Flies.
  - Abilities can be swapped during runtime (e.g., Unicorn switches to teleportation).
  
## Classes

### `Ability`

This is an **abstract base class** that defines the interface for all abilities. It contains a pure virtual function `performAbility()` that takes the creature's name as a parameter.
  
### `FireBreathing`, `Healing`, `Teleportation`, `Flight`

These are concrete classes derived from `Ability`. Each class implements the `performAbility()` function, simulating a specific ability:
- **FireBreathing**: Makes a creature breathe fire.
- **Healing**: Heals a wounded ally.
- **Teleportation**: Teleports a creature across the world.
- **Flight**: Makes a creature fly through the sky.

### `Creature`

This is an **abstract base class** for all creatures. It holds a pointer to an `Ability` object and has a pure virtual function `performAbility()`, which is overridden by derived creature classes.

### `Dragon`, `Unicorn`, `Phoenix`

These are concrete classes derived from `Creature`. Each represents a different mythical creature with a unique name and ability.

## Usage

1. **Create Ability Objects**: Instantiate different ability classes like `FireBreathing`, `Healing`, `Teleportation`, and `Flight`.
   
2. **Create Creature Objects**: Instantiate creatures like `Dragon`, `Unicorn`, or `Phoenix`, passing an ability object to the constructor.

3. **Perform Abilities**: Call the `performAbility()` method of a creature, which will invoke the ability specific to that creature.

4. **Change Abilities**: Creatures' abilities can be reassigned at runtime.