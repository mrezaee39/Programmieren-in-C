cmake_minimum_required(VERSION 3.15)
project(Building_C_Programs C)

set(CMAKE_C_STANDARD 99)

add_library(test_library STATIC
        main.c
        test.c
        fibonacci_test.c)

add_executable(Building_C_Programs fibonacci.c "../4 Data Types A - Primitive Types/main.c")
target_link_libraries(Building_C_Programs test_library)