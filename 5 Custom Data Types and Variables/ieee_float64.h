#ifndef _IEEE_FLOAT64_H_
#define _IEEE_FLOAT64_H_
#include <stdint.h>
#include <ieee754.h>
typedef union ieee_float64 ieee_float64;

union ieee_float64 {
    struct {
        uint64_t mantisse :52;
        unsigned int exponent :11;
        unsigned int sign :1;
    } fields;
    double number;
};

#endif //_IEEE_FLOAT64_H_
