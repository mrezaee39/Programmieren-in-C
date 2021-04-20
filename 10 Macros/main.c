#include "debug.h"

int
main(void)
{
    debug_print(DEBUG_LEVEL_ERROR, "%s\n", "ich bin ein debug string!");
    debug_print(DEBUG_LEVEL_WARNING, "%s\n", "ich bin ne warning!");
}