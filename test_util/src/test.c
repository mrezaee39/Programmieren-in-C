#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "test_util/test.h"
#include "test_util/src/test.h"

#define assertEqualDef(TYPE, SUFFIX, FORMAT_STRING) bool \
assertEqual ## SUFFIX(TYPE expected, TYPE actual) \
{\
    if (expected == actual) \
    { \
        printOk(); \
        return true; \
    } \
    else \
    { \
        setCommandLineColorToRed(); \
        printf("Fail.\texpected:" #FORMAT_STRING ", but got " #FORMAT_STRING "\n", expected, actual); \
        return false; \
    } \
}

assertEqualDef(uint64_t , LongHex, 0x%lx)
assertEqualDef(int32_t , IntHex, 0x%x)
assertEqualDef(float, Float, %f)
assertEqualDef(double, Double, %2.20e)
assertEqualDef(int32_t, Int, %i)
assertEqualDef(uint32_t , UInt, %u)

bool
assertEqualIntWithMessage(int32_t expected, int32_t actual, const char *message)
{
    printMessage(message);
    return assertEqualInt(expected, actual);
}

bool
assertLessInt(int32_t expected, int32_t actual)
{
    if (expected < actual)
    {
        printOk();
        return true;
    }
    else
    {
        setCommandLineColorToRed();
        printf("Fail.\texpected a number < %i, but got: %i\n", expected, actual);
        return false;
    }
}

bool
assertGreaterInt(int32_t expected, int32_t actual)
{
    if (expected > actual)
    {
        printOk();
        return true;
    }
    else
    {
        setCommandLineColorToRed();
        printf("Fail.\texpected a number > %i, but got: %i\n", expected, actual);
        return false;
    }
}

bool
assertLessLong(int64_t expected, int64_t actual)
{
    if (expected < actual)
    {
        printOk();
        return true;
    }
    else
    {
        setCommandLineColorToRed();
        printf("Fail.\texpected a number < %ld, but got: %ld\n", expected, actual);
        return false;
    }
}

void
printTestIndex(int32_t index)
{
    resetCommandLineColor();
    printf("test index %i: ", index);
}

void
setCommandLineColorToRed(void)
{
    printf("\x1b[31m");
}

void
setCommandLineColorToGreen(void)
{
    printf("\x1b[32m");
}

void
resetCommandLineColor(void)
{
    printf("\x1b[0m");
}

void
printMessage(const char *message)
{
    resetCommandLineColor();
    printf("%s: ", message);
}

void
printOk(void)
{
    setCommandLineColorToGreen();
    printf("Ok.\n");
}

int
evaluateTestSuite(TestSuite *suite)
{
    bool all_tests_passed = true;
    for (int i=0; i < suite->number_of_tests; i++)
    {
        all_tests_passed &= suite->passed[i];
        if (!suite->passed[i])
        {
            setCommandLineColorToRed();
            printf("Test Nr. %i failed.\n", i);
            resetCommandLineColor();
        }
    }
    return !all_tests_passed;
}


void
initTestSuite(TestSuite *suite) {
    memset(suite->passed, 1, suite->number_of_tests);
    suite->current_test_number = 0;
}

void
addFailResult(TestSuite *suite)
{
    suite->passed[suite->current_test_number] = false;
    suite->current_test_number++;
}

void
addPassResult(TestSuite *suite)
{
    suite->passed[suite->current_test_number] = true;
    suite->current_test_number++;
}

void
addTestResult(TestSuite *suite, bool passed)
{
    if (passed)
    {
        addPassResult(suite);
    } else {
        addFailResult(suite);
    }
}

TestSuite *
createTestSuite(uint8_t maximum_number_of_tests)
{
    TestSuite *suite = malloc(sizeof(TestSuite));
    suite->current_test_number = 0;
    suite->number_of_tests = maximum_number_of_tests;
    suite->passed = malloc(maximum_number_of_tests);
    initTestSuite(suite);
    return suite;
}

void
destroyTestSuite(TestSuite **suite)
{
    free((*suite)->passed);
    free(*suite);
    *suite = NULL;
}