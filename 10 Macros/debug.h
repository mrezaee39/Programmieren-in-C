#ifndef PROGRAMMING_C_DEBUG_H
#define PROGRAMMING_C_DEBUG_H

#include <stdio.h>

enum {
    DEBUG_LEVEL_NO_OUTPUT = 0,
    DEBUG_LEVEL_ERROR = 1,
    DEBUG_LEVEL_WARNING = 2,
    DEBUG_LEVEL_VERBOSE = 3,
};

#ifndef DEBUG_LEVEL
 #error "you have to define DEBUG to be either DEBUG_LEVEL_NO_OUTPUT, ...."
#endif

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
