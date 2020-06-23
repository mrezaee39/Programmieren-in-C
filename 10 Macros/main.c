#define DEBUG_LEVEL DEBUG_VERBOSE
#include "debug.h"


int main(void)
{
    debug_print(DEBUG_WARNINGS, "%s", "this is a warning\n");
    debug_print(DEBUG_INFO, "%s", "this is some debug info\n");
    debug_print(DEBUG_VERBOSE, "%s %i", "some text and a number: ", 42);
}