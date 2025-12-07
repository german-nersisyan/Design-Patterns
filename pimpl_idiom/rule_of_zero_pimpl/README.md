# Matrix Class Implementation

This project provides a simple implementation of a `Matrix` class in C++ that supports operations like filling a matrix with a given value and calculating the trace of a matrix. The matrix is implemented using the **Rule of Zero** and the **PImpl** (Pointer to Implementation) idiom for better encapsulation and to minimize compilation dependencies.

The **Rule of Zero** ensures that the class doesn't manually manage resources (like dynamic memory) directly. This is achieved by using `std::shared_ptr` to manage the lifetime of the `Impl` class, meaning no custom destructors, copy constructors, or assignment operators are needed. This makes the class safer, simpler, and more maintainable.

## Features

- **Matrix Creation**: You can create matrices of any size (rows x columns).
- **Fill Matrix**: The matrix can be filled with a given value using the `fill()` method.
- **Trace Calculation**: The trace of the matrix (the sum of the diagonal elements) can be computed using the `trace()` method.
- **Copying**: The `Matrix` class supports copying, allowing you to clone matrices.