# HTML-like Structure Rendering with Composite design pattern

This C++ program demonstrates a simple implementation of an HTML-like document structure using the Composite design pattern. It allows for the construction and rendering of HTML elements such as `<html>`, `<body>`, `<div>`, and `<p>`, along with textual content. The rendering function produces an indented representation of the document structure, simulating a formatted HTML output.

## Features

- **Composite Pattern**: Uses the Composite design pattern to represent a tree-like structure where each node can either be a simple text node or an element node with children.
- **Text Nodes**: Represents text content within elements (Leaf).
- **Element Nodes**: Represents HTML-like elements (`<html>`, `<body>`, `<div>`, etc.) with possible child elements or text nodes (Composite).
- **Indentation-based Rendering**: The `render` function produces a hierarchical, indented output that mimics the formatting of HTML documents.