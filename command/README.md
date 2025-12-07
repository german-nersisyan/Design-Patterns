# ⏳ Time Machine Command Pattern

This project implements a **Time Machine** simulation using the **Command Design Pattern**. The Time Machine allows users to execute various time-related commands, such as traveling to the past, altering historical events, and more. The program also supports the ability to **undo** the most recent command, simulating the reversal of time-based actions.

## Overview

The program defines a **Command** interface and several concrete command classes for different time-related actions. These commands are executed by a `TimeMachine` object and can be undone in reverse order of their execution. The following commands are supported:

- **TravelToPastCommand**: Simulates traveling to a specific year in the past.
- **AlterBerlinWallEventCommand**: Simulates altering an event related to the Berlin Wall.
- **RestoreTimelineCommand**: Restores the timeline to its original state after making changes.
- **VisitFutureCommand**: Simulates traveling to the future to observe the effects of past changes.

## How it Works

This project uses the **Command Design Pattern** to encapsulate each time-related action into a separate command object. The `TimeMachine` class is responsible for executing and undoing these commands:

1. **Command Interface**: Defines two methods — `execute()` (to perform the command) and `undo()` (to reverse the command).
2. **Concrete Command Classes**: Implement the `Command` interface for specific actions, like traveling to the past or altering events.
3. **TimeMachine Class**: Executes and undoes commands. It maintains a history of executed commands to allow undos.

## Features

- **Execute Commands**: Users can execute various time-related actions.
- **Undo Command**: The most recently executed command can be undone, reversing the action.
- **History Tracking**: The `TimeMachine` maintains a history of executed commands to allow undos in reverse order.