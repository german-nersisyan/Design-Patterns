# 🧩 PuzzleHandler Chain of Responsibility Pattern

This C++ program demonstrates the implementation of the **Chain of Responsibility** design pattern, where multiple handlers are chained together to process different aspects of a puzzle-solving scenario. Each handler in the chain performs a specific task related to solving a puzzle, such as providing hints, identifying traps, rewarding the player, and revealing a story. The chain is traversed sequentially, allowing for flexible and extensible handling of various puzzle-solving stages.

## Design Overview

The program defines four main handlers that process different stages of solving a puzzle:

1. **HintHandler** - Provides hints to the player to help solve the puzzle.
2. **TrapHandler** - Warns the player about potential traps or misleading clues.
3. **RewardHandler** - Rewards the player with treasure after successfully solving the puzzle.
4. **StoryHandler** - Ties the puzzle into a narrative, revealing the legend of the treasure hunt.

Each handler is part of a chain, and when one handler has finished its task, it passes the puzzle to the next handler in the chain.

## How It Works

- Each handler implements the `PuzzleHandler` interface and provides a concrete implementation of the `solvePuzzle()` function.
- The handlers are linked together using the `setNext()` method, where one handler points to the next handler in the chain.
- In the `main()` function, the handlers are instantiated, connected, and the puzzle-solving process is initiated by calling `solvePuzzle()` on the first handler in the chain.