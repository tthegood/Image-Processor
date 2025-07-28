# C++ Image Processing Module

This project provides a lightweight C++ library for loading, saving, and processing PGM images.

## Features

- **Load/Save** PGM (Portable Graymap) images
- **Sobel Filter** for edge detection
- Manual memory management using `std::unique_ptr` for efficiency
- Unit tests with CTest

## Prerequisites

- C++17 compiler
- CMake >= 3.10
- Git

## Build & Test

```bash
cd cpp-image-processing-module
mkdir build && cd build
cmake ..
make
ctest --output-on-failure