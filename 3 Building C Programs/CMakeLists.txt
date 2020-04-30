cmake_minimum_required(VERSION 3.15)
project(Building_C_Programs C)

set(CMAKE_C_STANDARD 99)

add_executable(Building_C_Programs main.c test.c test.h fibonacci.h fibonacci_test.c fibonacci_test.h fibonacci.c)