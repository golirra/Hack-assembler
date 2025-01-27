# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyProject)

# Specify the C standard (optional)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the executable
add_executable(my_program assembler.c)

