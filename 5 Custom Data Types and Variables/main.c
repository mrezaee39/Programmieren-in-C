#include <stdbool.h>
#include "exercise.h"
#include <stdio.h>

void
assertFloatEquals(ieee_float64 left, ieee_float64 right)
{

}

int
main(void)
{

    bool all_tests_pass = test_runner();\
    printf("size of ieee float 64 bit: %lu\n", sizeof(ieee_float64));

    ieee_float64 first = {
            .number = 0.3
    };
    ieee_float64 second = {
            .number = 3*0.1
    };
    assertFloatEquals(first, second);

    if (all_tests_pass)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}