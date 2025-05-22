# CMake Template for General Fortran/C/C++ Projects

Build systems are essential for managing the complexity of modern software development. This template provides a starting point for creating a CMake-based build system for Fortran, C, and C++ projects. It includes support for unit testing, code coverage, and continuous integration.

CMake is a powerful tool that can be used to manage the build process of complex software projects. It is widely used in the scientific computing community and is supported by many IDEs, including Visual Studio, Xcode, and CLion.
It relies on a top level file called `CMakeLists.txt` to define the build process. This file contains a series of commands that specify how to build the project, including the source files, libraries, and compiler options.

## Table of Contents


## List of sources:
Below are some of the sources used as inspriration to create this template:

- [CMake FULL practical Guide!] https://www.youtube.com/watch?v=IBgfeZME2Vw
- [CMake Tutorial] https://www.youtube.com/watch?v=DDHCEE_PHOU&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4&index=1
## CMake (introduction))

This is a build system generator that can allow for cross-platform builds. It is a powerful tool that can be used to manage the build process of complex software projects. CMake is widely used in the scientific computing community and is supported by many IDEs, including Visual Studio, Xcode, and CLion.

## Modular Design





## Directory Structure
```plaintext
src/
	├── main.cpp
	├── main.f90
	├── main.c
	└── CMakeLists.txt
	tests/
	├── test_main.cpp
	├── test_main.f90
	├── test_main.c
	└── CMakeLists.txt
	include/
	├── main.hpp
	└── main.f90
	CMakeLists.txt
```


# CMake Tutorial 

This documentation relies on a number of sources and includes this tutorial that is used to create the general configuration of the CMake files that build the application or libraries with minor configuration. The tutorial section below is largely comprised of notes and code snippet exaples from the official CMake repo at : https://cmake.org/cmake/help/v3.31/guide/tutorial/Adding%20a%20Library.html


## Starting Point

The most basic CMakeLists.txt file contains three commands. The set the minimum CMake version required, gives the build a name, and adds the executable content included wihtin the build.


```CMake
cmake_minimum_required(VERSION <version number>)
add_library(<project_name> <files>)
project(<project_name> VERSION 1.0.0 LANGUAGES CXX)
```





## Creating .dll in CMake





