#include "exercise.h"


int main(void)
{
    bool all_tests_pass = true;
    all_tests_pass &= test_shortDataTypeSize();
    all_tests_pass &= test_textLength();
    all_tests_pass &= test_countToLargeNumber();
    all_tests_pass &= test_multiply();
    all_tests_pass &= test_initializeInt();
    all_tests_pass &= test_incrementDouble();

    if (all_tests_pass)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}