# ↕️ Elevator Control System with state pattern

This project simulates a basic Elevator Control System that manages multiple elevators and handles requests to move between floors. It implements a **State Design Pattern** to manage the different elevator states, including idle, moving up, moving down, and doors open/closed.

## Features

- **State Management:** The elevator can be in different states, including:
  - **Idle:** The elevator is not moving and is waiting for user requests.
  - **Moving Up:** The elevator is moving upwards.
  - **Moving Down:** The elevator is moving downwards.
  - **Doors Open/Closed:** Manages door states (open/closed) during operation.
  
- **Elevator Requests:** Users can request an elevator to move to a specific floor, and the control system assigns the nearest idle elevator.

- **Multiple Elevators:** The system supports multiple elevators, which can operate independently of each other.

- **Elevator Assigning:** The control system automatically assigns the nearest idle elevator to handle the request.

## Architecture

### Classes

- **ElevatorState (abstract class):** 
  - Base class for all elevator states. It defines common actions that all states should implement, such as `handleRequest`, `buttonPressed`, `doorOperation`, `moveElevator`, and `isIdle`.
  
- **IdleState, MovingUpState, MovingDownState, DoorsOpenState, DoorsClosedState:**
  - Concrete implementations of `ElevatorState`. Each represents a different state of the elevator (idle, moving up, moving down, doors open/closed) and provides specific behavior for the elevator's actions.

- **Elevator:**
  - Represents a single elevator. It maintains the current floor and state of the elevator. It can switch states, move to a requested floor, and open/close doors. Each elevator operates independently of others.

- **ElevatorControlSystem:**
  - Manages the collection of elevators. It handles floor requests from users and assigns the nearest available elevator to handle the request.

### Key Operations

- **callElevator(floor):** 
  - Requests an elevator to a specific floor.
  
- **moveToFloor(targetFloor):**
  - Moves the elevator to the target floor, changing states based on whether the elevator needs to move up or down.