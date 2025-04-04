# CS 403 Assignment #5: Polymorphism in C++

**Author:** Walter Mink  
**Course:** CS 403 – Programming Languages  
**Institution:** The University of Alabama  

---

## Academic Integrity Notice

**WARNING:** This repository contains code that I, Walter Mink, developed independently for my own studies. 
To be completely clear, directly copying, submitting, or presenting my work as your own is considered academic misconduct / plagarism, not just at the University of Alabama, but at practically every university in existence. My code is purely here for reference, educational insight, and to fill out my portfolio. Under no circumstances should you misuse or plagarize this code, and I claim no responsibility for consequences resulting from you ignoring this warning and doing so.

---

## Repository Overview

This repository contains my implementation of the fifth programming assignment for CS 403, "Programming Languages," at the University of Alabama. The primary objective of this assignment was to deepen our understanding of **polymorphism** in C++ through the practical implementation of a base class and multiple derived classes.

---

## Assignment Details

We were tasked with creating a C++ program demonstrating polymorphism by defining a base class named `Shape`, and four derived classes:

- **Sphere** (defined by radius)
- **Cylinder** (defined by radius and height)
- **Torus** (defined by small radius and big radius)
- **Box** (defined by length, width, and height)

The `Shape` base class includes four pure virtual functions:
- `getArea()`: calculates surface area
- `getVolume()`: calculates volume
- `getInfo()`: provides a formatted description of the shape
- `test()`: evaluates if the shape satisfies a given list of conditions

The shapes are read from a data file, structured as follows:
```
<name> sphere <radius>
<name> cylinder <radius> <height>
<name> torus <small_radius> <big_radius>
<name> box <length> <width> <height>
```

I implemented a `readFrom` function to process shape data files and dynamically create shape objects demonstrating polymorphic behavior.

---

## Files Included

- `Shape.h` and `Shape.cpp`: Base class definition provided by the instructor
- Derived classes (`Sphere`, `Cylinder`, `Torus`, `Box`): each with their own `.h` and `.cpp` files
- `Reading.h` and `Reading.cpp`: Functions to read and parse shape data from input files
- `main.cpp`: Provided by the instructor to test polymorphic behaviors
- `shapes.dat`: Sample data file containing shape definitions
- `Makefile`: Supports compilation (`make`) and cleanup (`make clean`)

---

## Compilation & Execution

Use the provided Makefile:
```shell
make
```

Execute the compiled program:
```shell
./a.out shapes.dat
```

Clean compiled files:
```shell
make clean
```
