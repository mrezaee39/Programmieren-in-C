#ifndef BUILDING_C_PROGRAMS_TEST_H
#define BUILDING_C_PROGRAMS_TEST_H

#include <stdbool.h>
#include <stdint.h>

bool
assertEqualInt(int32_t expected, int32_t actual);

bool
assertEqualIntHex(int32_t expected, int32_t actual);

bool
assertEqualIntWithMessage(int32_t expected, int32_t actual, const char *message);

bool
assertEqualLongHex(uint64_t expected, uint64_t actual);

bool
assertEqualFloat(float expected, float actual);

bool
assertEqualDouble(double expected, double actual);

bool
assertLessInt(int32_t expected, int32_t actual);

bool
assertGreaterInt(int32_t expected, int32_t actual);

bool
assertLessLong(int64_t expected, int64_t actual);

bool
assertEqualUInt(unsigned expected, unsigned actual);

void
printTestIndex(int32_t index);

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
evaluateTestSuite(TestSuite *);


void
initTestSuite(TestSuite *suite);

void
addFailResult(TestSuite *suite);

void
addPassResult(TestSuite *suite);

void
addTestResult(TestSuite *suite, bool passed);

/**
 * This mallocs some stuff free with the corresponding destroy function destroyTestSuite
 * @param maximum_number_of_tests
 * @return
 */
TestSuite *
createTestSuite(uint8_t maximum_number_of_tests);

void
destroyTestSuite(TestSuite **);

struct TestSuite
{
    bool *passed;
    uint8_t current_test_number;
    uint8_t number_of_tests;
};

#endif //BUILDING_C_PROGRAMS_TEST_H
