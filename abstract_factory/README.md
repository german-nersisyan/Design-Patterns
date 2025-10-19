# Movie Factory Design Pattern Example

This is a simple C++ implementation of the **Abstract Factory Design Pattern**. The program demonstrates how different movie studios (Disney and Paramount) can produce two types of movies: Comedy and Horror, each with its own specific implementation.

## Features

The program defines a system where:

1. **Comedy** and **Horror** are abstract classes representing two movie genres.
2. Each genre has different implementations depending on the studio:
   - `DisneyComedy`, `ParamountComedy` for comedy movies.
   - `DisneyHorror`, `ParamountHorror` for horror movies.
3. The `MovieFactory` abstract class is used to create families of related objects (Comedy and Horror movies). Two concrete factories (`DisneyFactory` and `ParamountFactory`) implement this interface and return the corresponding movies for their respective studios.