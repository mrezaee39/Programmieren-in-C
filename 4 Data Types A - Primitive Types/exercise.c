#include "exercise.h"
#include "test_util/test.h"
#include <stdint.h>
#include <stdio.h>
#include <limits.h>

bool
test_shortDataTypeSize(void) {
    return assertEqualIntWithMessage(sizeof(short), 2,
                                     "Which size does your system use for short data types?");
}


bool
test_textLength(void) {
    int text_length = 0;
    char text[] = "How long is this text?";

    // <your code that calculates the length of the string text goes here>
    return assertEqualIntWithMessage(22, text_length, "Calculated text length should be");
}

bool
test_countToLargeNumber(void) {
  int counter_value = 0;
  /*
   * The 5 lines below are commented out, because the code will not
   * terminate. How can you fix that problem?
   * How can we be sure the fix works for all people taking
   * the exercise?
   */
  printf("counter value: ");
  for (; counter_value <65535; counter_value++) {
    }

  printf("%i ", counter_value);

  return assertEqualInt(65535, counter_value);
}

bool
test_multiply(void) {
    // Why does the test below fail?
    // Assuming we do not want to change the value of the variable here,
    // how can you fix the test? (Hint: also take a look at the header file `test_util/test.h`)
    uint64_t factor = 1000000;
    return assertLessInt(0, factor * factor);
}

bool
test_initializeInt(void) {
    // With what you learned above,
    // initialize the variable below with the correct value
    // to make the test pass.

    unsigned int max_int = UINT_MAX-1;
    return assertEqualUInt(0, max_int + 1);
}

bool
test_incrementDouble(void) {
    // What do you think why the third test fails?
    double should_reach_03 = 0;
    should_reach_03 += 0.1;
    assertEqualDouble(0.1, should_reach_03);
    should_reach_03 += 0.1;
    assertEqualDouble(0.2, 0.2);
    should_reach_03 += 0.1;
    return assertEqualDouble(0.3, should_reach_03);
}