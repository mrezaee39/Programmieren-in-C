#include <stdbool.h>
#include "exercise.h"
#include <stdio.h>

void
printFloat(ieee_float64 number)
{
    printf("sign: 0x%ux, exponent: 0x%ux - %u, mantisse: 0x%lux\n",
            number.fields.sign,
            number.fields.exponent,
            number.fields.exponent-1023,
            number.fields.mantisse);

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
    printFloat(first);
    printFloat(second);

    if (all_tests_pass)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}