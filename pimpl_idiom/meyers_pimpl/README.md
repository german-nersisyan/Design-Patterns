# Timer Class

A simple, thread-safe timer class that measures elapsed time using `std::chrono`. This implementation employs the **Meyers' PImpl idiom** (Pointer to Implementation) to separate the interface from the implementation details, allowing better encapsulation, modularity, and potential future optimizations.

## Features

- Measures elapsed time in seconds.
- Can be reset to start timing from the current moment.
- Provides thread-safety by using `std::chrono::steady_clock`.
- Simple and easy-to-use interface for timing in C++ applications.
- Uses the PImpl (Pointer to Implementation) idiom to hide implementation details.

## Meyers' PImpl Idiom

This class uses **Scott Meyers' PImpl idiom** (Pointer to Implementation) to separate the public interface of the `Timer` class from its implementation. The `Timer` class holds a pointer to a private implementation (`Impl`), which contains the actual logic for timing. This provides several benefits:

- **Encapsulation**: The implementation details (e.g., how time is measured and stored) are hidden from the user.
- **Faster Compilation**: Changes to the implementation do not require recompilation of code that uses the `Timer` class, since the implementation is hidden behind a pointer.
- **Binary Compatibility**: Changes to the implementation (e.g., adding new members) do not affect the size of the public interface, helping maintain binary compatibility across library versions.