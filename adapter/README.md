# Grading System Adapter

This project demonstrates the use of the Adapter Design Pattern to integrate an old grading system with a new letter grading system. The purpose of the adapter is to convert a numeric score from the old system into a letter grade in the new system.

The project contains two implementations of this idea:

1. **Adapter Pattern using Composition**: The first implementation uses a dedicated `GradingAdapter` class that acts as an adapter between the old grading system and the new letter grading system.
2. **Adapter Pattern using Multiple Inheritance**: The second implementation uses multiple inheritance to combine both grading systems directly in the `GradingAdapter` class.

## Features

The project consists of four classes in total:

1. **OldGradingSystem**: Represents an old grading system that accepts numeric scores.
2. **LetterGradingSystem**: Represents a new grading system that provides letter grades (A, B, C, D, F).
3. **GradingAdapter (Composition)**: An adapter class that uses composition to integrate the old and new grading systems.
4. **GradingAdapter (Multiple Inheritance)**: An adapter class that uses multiple inheritance to combine the old and new grading systems.

Both `GradingAdapter` classes allow code using the old system to also handle letter grades.