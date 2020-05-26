#ifndef BUILDING_C_PROGRAMS_TEST_H
#define BUILDING_C_PROGRAMS_TEST_H

#include <stdbool.h>
#include <stdint.h>

bool
assertEqualInt(int expected, int actual);

bool
assertEqualIntHex(int expected, int actual);

bool
assertEqualIntWithMessage(int expected, int actual, const char *message);

bool
assertEqualLongHex(unsigned long expected, unsigned long actual);

bool
assertEqualFloat(float expected, float actual);

bool
assertEqualDouble(double expected, double actual);

bool
assertLessInt(int expected, int actual);

bool
assertGreaterInt(int expected, int actual);

bool
assertLessLong(long expected, long actual);

bool
assertEqualUInt(unsigned expected, unsigned actual);

void
printTestIndex(int index);

typedef struct TestSuite TestSuite;

/**
 * Checks the passed member of a test suite and
 * returns the matching exit code for the main function.
 * Intended use case is
 * ```
 * int main(void){
 *   test_myTest();
 *   return evaluateTestSuite(my_test_suite);
 * }
 */
int
evaluateTestSuite(TestSuite);

struct TestSuite
{
    bool passed;
    uint8_t number_of_tests;
};

#endif //BUILDING_C_PROGRAMS_TEST_H
