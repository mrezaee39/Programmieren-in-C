#include <stdbool.h>
#include "exercise.h"


int
main(void)
{

    bool all_tests_pass = test_runner();
    if (all_tests_pass)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}