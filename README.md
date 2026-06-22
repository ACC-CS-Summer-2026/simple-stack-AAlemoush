# Stack ADT Demonstration (C++)

A C++ project demonstrating a fundamental Abstract Data Type (ADT) by implementing a static integer Stack. Concepts included:
- Basic class design (constructors, accessors, mutators, and private attributes)
- Handling state conditions (underflow and overflow)
- Pass-by-reference for returning values while simultaneously indicating success/failure states
- Dynamic and exhaustive testing using explicit and random operations scaled to the stack size
- Elimination of hardcoded literals using macros and constants

## Project Structure

- `main.cpp` / `main.h`: The application entry point, comprehensive testbed driver, and core includes/constants.
- `stack.h` / `stack.cpp`: The `Stack` class definition and implementation containing the static array, top tracker, and core stack operations (`push`, `pop`, `peek`, `isEmpty`).
- `README.md`: This file.
- `essay.md`: Reflections on the development process.

## Build and Run Instructions (Linux)

From the main project directory, compile the source files using `g++` and execute the compiled binary:

```bash
g++ -I ./ *.cpp
./a.out