#ifndef PROGRAMMING_C_DEBUG_H
#define PROGRAMMING_C_DEBUG_H

#include <stdio.h>

#ifndef DEBUG_LEVEL
    #error "You have to define a DEBUG_LEVEL of DEBUG_NO_OUTPUT: no output, DEBUG_ERROR: only critical errors leading to program exit"\
    ", DEBUG_WARNINGS: warnings, DEBUG_INFO: info, DEBUG_VERBOSE: verbose"
#endif

enum {
    DEBUG_NO_OUTPUT,
    DEBUG_ERROR,
    DEBUG_WARNINGS,
    DEBUG_INFO,
    DEBUG_VERBOSE,
};

#define debug_print(debug_level, fmt, ...) \
  do { \
    if (DEBUG_LEVEL >= debug_level) \
        fprintf(stderr, \
            "%s:%i: " fmt, \
            __FILE__, \
            __LINE__, \
            __VA_ARGS__); \
    } while (0)

#endif //PROGRAMMING_C_DEBUG_H
