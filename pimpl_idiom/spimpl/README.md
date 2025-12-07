# Car Simulator Project

This is a C++ project that simulates the behavior of a car, demonstrating the **Smart PImpl (SPImpl)** idiom (a variation of the Pointer to Implementation pattern) for separation of interface and implementation. The program provides a simple simulation of car operations, such as starting the engine and driving, with a focus on efficient memory management and abstraction.

## Features

- **Smart PImpl (SPImpl)**: The `Car` class hides its internal implementation details using the Smart PImpl idiom. This is an enhanced version of the traditional PImpl idiom that uses `std::unique_ptr` to ensure automatic memory management. This design pattern helps separate the interface from the implementation, improving maintainability, reducing compile-time dependencies, and ensuring better resource management through smart pointers.
- **Basic Car Simulation**: The car has simple operations:
  - `startEngine()`: Starts the car's engine.
  - `drive()`: Simulates driving the car (only possible if the engine is started).
- **Separation of Concerns**: The implementation details are encapsulated in the private `CarImpl` class, which is managed by a `std::unique_ptr` to ensure proper memory handling and prevent memory leaks.