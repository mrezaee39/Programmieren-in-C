#include <stdio.h>
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

assertEqualDef(unsigned long, LongHex, 0x%lx)
assertEqualDef(int, IntHex, 0x%x)
assertEqualDef(float, Float, %f)
assertEqualDef(double, Double, %2.20e)
assertEqualDef(int, Int, %i)
assertEqualDef(unsigned, UInt, %u)

bool
assertEqualIntWithMessage(int expected, int actual, const char *message)
{
    printMessage(message);
    return assertEqualInt(expected, actual);
}

bool
assertLessInt(int expected, int actual)
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
assertGreaterInt(int expected, int actual)
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
assertLessLong(long expected, long actual)
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
printTestIndex(int index)
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
evaluateTestSuite(TestSuite suite)
{
    return !suite.passed;
}