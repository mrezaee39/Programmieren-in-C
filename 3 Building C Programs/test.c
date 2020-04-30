#include <stdio.h>
#include "3 Building C Programs/test.h"

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
assertEqualIntWithMessage(int expected, int actual, const char *message)
{
    resetCommandLineColor();
    printf("%s: ", message);
    assertEqualInt(expected, actual);
}

void
assertEqualInt(int expected, int actual)
{
    if (expected == actual)
    {
        setCommandLineColorToGreen();
        printf("Ok.\n");
    }
    else
    {
        setCommandLineColorToRed();
        printf("Fail.\texpected: %i, but got: %i\n", expected, actual);
    }
}
