# Image Class

This project implements an `Image` class that provides basic image manipulation operations such as filling the image with a specific color, inverting the image's colors, and getting information about the image's dimensions and pixel data.

The `Image` class uses the **PImpl Idiom** (Pointer to Implementation) to encapsulate the details of the image representation and provides a clean and easy-to-use interface.

## Features

- **Image Creation**: Supports image creation with specified width and height.
- **Color Manipulation**:
  - `fill(r, g, b)`: Fills the image with a specified RGB color.
  - `invert_colors()`: Inverts the colors of the image.
- **Copy and Move Semantics**: Supports both copy and move constructors, and assignment operators.
- **Image Information**: Provides information about the image's size and pixel count through the `info()` method.