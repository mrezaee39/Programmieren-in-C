#include <stdbool.h>
#include "exercise.h"
#include "test_util/test.h"
#include <stdio.h>

/**
 * At the bottom of this file you will find a test runner function.
 * You do not have to understand all details of it (will be covered
 * in later lectures). You only need to know that it will
 * run each of the `test` functions below in the order
 * they appear here in the code.
 *
 * You will have to create the correct data type to make the tests pass.
 */



bool
test_custom_float_has_assignable_fields(void)
{
    ieee_float64 my_float;
    my_float.fields.sign = 1;
    my_float.fields.mantisse = 2;
    my_float.fields.exponent = 3;
    bool successful = assertEqualInt(1, my_float.fields.sign);
    successful &= assertEqualInt(2, my_float.fields.mantisse);
    successful &= assertEqualInt(3, my_float.fields.exponent);
    return successful;
}

bool
test_custom_float_sign_is_negative(void)
{
    ieee_float64 my_float;
    my_float.number = 1.;
    return assertEqualInt(0, my_float.fields.sign);
}

bool
test_custom_float_sign_is_positive(void)
{
    ieee_float64 my_float = {.number = -1.};
    return assertEqualInt(1, my_float.fields.sign);
}

bool
test_custom_float_mantisse_is_correct(void)
{
    ieee_float64 my_float = {.number = 1.5};
    assertEqualLongHex(0x8000000000000, my_float.fields.mantisse);
    return assertEqualInt(1022, my_float.fields.exponent);
}

bool
test_custom_float_exponent_is_correct(void)
{
    ieee_float64 my_float = {.number = 2};
    assertEqualInt(1024, my_float.fields.exponent);
}


bool
test_runner(void)
{
    bool all_tests_pass = true;
    bool (*test_functions[])(void) = {
            test_custom_float_has_assignable_fields,
            test_custom_float_sign_is_negative,
            test_custom_float_sign_is_positive,
            test_custom_float_mantisse_is_correct,
            test_custom_float_exponent_is_correct,
    };
    int NUMBER_OF_TESTS = 5;
    printf("Executing %i tests.\n", NUMBER_OF_TESTS);
    for (int test_index = 0; test_index < NUMBER_OF_TESTS; test_index++)
    {
        printTestIndex(test_index);
        bool (*current_test)(void) = test_functions[test_index];
        bool passed = current_test();
        all_tests_pass &= passed;
    }
    return all_tests_pass;
}