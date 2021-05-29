#include "exercise.h"
#include <stdlib.h>
#include <stdio.h>


int
main(void)
{
  float left_data[] = {1.5f, 2, 3};
  Vector left = {
      .data = left_data,
      .length = sizeof(left_data) / sizeof(float)
  };
  float right_data[] = {3, 2, 1};
  Vector right = {
      .data = right_data,
      .length = sizeof(right_data) / sizeof(float)
  };
  float s = sum (left);
  printf("%f == 6.5\n", s);
  float result = dot (left, right);
  printf("%f\n", result);
  return EXIT_SUCCESS;
}