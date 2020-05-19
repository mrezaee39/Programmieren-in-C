#ifndef BUILDING_C_PROGRAMS_TEST_H
#define BUILDING_C_PROGRAMS_TEST_H

#include <stdbool.h>
#include <stdint.h>

bool
assertEqualInt(int expected, int actual);

bool
assertEqualIntWithMessage(int expected, int actual, const char *message);

bool
assertEqualFloat(float expected, float actual);

bool
assertEqualDouble(double expected, double actual);

bool
assertLessInt(int expected, int actual);

bool
assertGreaterInt(int expected, int actual);

bool
assertLessLong(long expected, long actual);

bool
assertEqualUInt(unsigned expected, unsigned actual);

bool
assertLessUInt64(uint64_t expected, uint64_t actual);

#endif //BUILDING_C_PROGRAMS_TEST_H
