# PICUP
Particle-In-Cell Utility for Practice

## Goals of this project
The primary goal of this project is to develop a basic particle-in-cell
code.
This code may be used for basic validation and investigation.

The secondary goals for this project include:
 * Learning the methods used for particle-in-cell codes
 * Learning/practicing object-oriented programming
 * Fun

### Guiding Principles
 * Object-Oriented Programming and using templates where possible
 * Testing Driven Development (TDD) - lite
   * When possible or practical unit tests should be developed before
     code, but this need not be strongly enforced

## Building with CMake
Type the following commands into the terminal to build on Linux systems.

    mkdir build; cd build
    cmake ../
    make

### Dependencies
These packages are required to build PICUP.
 * [CMake](https://www.cmake.org/) (>= 2.8.12.2)
 * [Doxygen](https://www.doxygen.org/)

#### Included libraries and frameworks
This project includes source code from several other projects.
 * [GoogleTest](https://www.github.com/google/googletest)
   and [GoogleMock](https://www.github.com/google/googletest/tree/
   master/googlemock)
 * Portions of [Eigen](http://www.eigen.tuxfamily.org/)
