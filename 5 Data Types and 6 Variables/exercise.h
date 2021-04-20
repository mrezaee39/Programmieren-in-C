#ifndef PROGRAMMING_C_EXERCISE_H
#define PROGRAMMING_C_EXERCISE_H

#include <stdint.h>

typedef union ieee_float64 ieee_float64;

union ieee_float64
{
    struct
    {
        uint64_t mantisse: 52; // 52 bit
        unsigned exponent: 11; // 11 bit

        unsigned sign: 1; // 1 bit
    } fields;
    double number;
};

bool
test_runner(void);

#endif //PROGRAMMING_C_EXERCISE_H
