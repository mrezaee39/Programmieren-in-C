#include <stdio.h>
#include "test_util/test.h"
#include "test_util/src/test.h"

bool
assertEqualIntWithMessage(int expected, int actual, const char *message)
{
    printMessage(message);
    return assertEqualInt(expected, actual);
}

bool
assertEqualInt(int expected, int actual)
{
    if (expected == actual)
    {
        printOk();
        return true;
    }
    else
    {
        setCommandLineColorToRed();
        printf("Fail.\texpected: %i, but got: %i\n", expected, actual);
        return false;
    }
}

bool
assertEqualFloat(float expected, float actual)
{
    if (expected == actual)
    {
        printOk();
        return true;
    } else{
        setCommandLineColorToRed();
        printf("Fail.\texpected: %f, but got: %f\n", expected, actual);
        return false;
    }
}

bool
assertEqualDouble(double expected, double actual)
{
    if (expected == actual)
    {
        printOk();
        return true;
    } else{
        setCommandLineColorToRed();
        printf("Fail.\texpected: %.20e, but got: %.20e\n", expected, actual);
//        printf("hexadecimal representations:\n\t%lx\n\t%lx\n",
//                *(unsigned long *)(&expected),
//                *(unsigned long *)(&actual));
        return false;

    }
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

bool
assertEqualUInt(unsigned expected, unsigned actual)
{
    if (expected == actual)
    {
        printOk();
        return true;
    }
    else
    {
        setCommandLineColorToRed();
        printf("Fail.\texpected %u, but got: %u\n", expected, actual);
        return false;
    }
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