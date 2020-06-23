#include <stdint.h>
#include "debug.h"

int sum(int a, int b)
{
    int result = a + b;
    return result;
}

int
main(void)
{
    int s = sum(1,2);
    long *a = &s;
    uint8_t byte = 0x05;
    char *c = (char *)&byte;
    debug_print(DEBUG_LEVEL_ERROR, "%s: %i\n", "ich bin ein debug string!", s);
    debug_print(DEBUG_LEVEL_WARNING, "%s\n", "ich bin ne warning!");
}