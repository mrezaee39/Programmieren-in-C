#include <stdbool.h>
#include "exercise.h"

void
printFloat(ieee_float64 number)
{
    printf("sign: 0x%x, exponent: 0x%x - %i, mantisse: 0x%lx\n",
            number.fields.sign,
            number.fields.exponent,
            number.fields.exponent-1023,
            number.fields.mantisse);

}

int
main(void)
{

    bool all_tests_pass = test_runner();\
    printf("size of ieee float 64 bit: %i\n", sizeof(ieee_float64));

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