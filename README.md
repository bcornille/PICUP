# PICUP
[![Build Status](https://travis-ci.org/bcornille/PICUP.svg?branch=develop)](https://travis-ci.org/bcornille/PICUP)
Particle-In-Cell Utility for Practice

#### See Also
[Git Repository](https://github.com/bcornille/PICUP)

[Online Documentation](http://bcornille.github.io/PICUP)

## Goals of this project
The primary goal of this project is to develop a basic particle-in-cell code.
This code may be used for basic validation and investigation.

The secondary goals for this project include:
* Learning the methods used for particle-in-cell codes
* Learning/practicing object-oriented programming
* Fun

## Building with CMake
Type the following commands into the terminal to build on Linux systems.

    mkdir build; cd build
    cmake ../
    make

### Dependencies
These packages are required to build PICUP.
 * [CMake](https://cmake.org/) (>= 2.8.12.2)
 * [Doxygen](http://www.stack.nl/~dimitri/doxygen/)

#### Included libraries and frameworks
This project includes source code from several other projects.
 * [GoogleTest](https://github.com/google/googletest)
   and [GoogleMock](https://github.com/google/googletest/tree/master/googlemock)
 * Portions of [Eigen](http://eigen.tuxfamily.org/)
