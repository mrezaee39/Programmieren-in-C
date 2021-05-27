#include "exercise.h"

Vector
multiply (Vector left, Vector right, float *out_buffer)
{
  Vector result = {.length = left.length, .data = out_buffer};
  for (int index = 0; index < left.length; index++)
  {
    out_buffer[index] = right.data[index] * left.data[index];
  }
  return result;
}

float
sum (Vector vector)
{
  float result = 0;
  for (int index = 0; index < vector.length; index++)
  {
      result += vector.data[index];
  }
  return result;
}

float
dot (Vector left, Vector right)
{
  float data[left.length];
  Vector intermediate_result = multiply (left, right, data);
  float result = sum (intermediate_result);
  return result;
}