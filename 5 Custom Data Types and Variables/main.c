#include <stdbool.h>
#include "exercise.h"
#include <stdio.h>
#include "ieee_float64.h"

bool
assertFloatEquals (ieee_float64 left, ieee_float64 right)
{
  if (left.number == right.number)
    {
      return true;
    }
  if (left.fields.mantisse != right.fields.mantisse)
    {
      printf ("left mantisse: 0x%lx\n", left.fields.mantisse);
      printf ("right mantisse: 0x%lx\n", right.fields.mantisse);
    }
  if (left.fields.exponent != right.fields.exponent)
    {
      printf ("left exponent: %lu\n", left.fields.exponent);
      printf ("right exponent: %lu\n", right.fields.exponent);
    }
  if (left.fields.sign != right.fields.sign)
    {
      printf ("left sign: %i", left.fields.sign);
      printf ("right sign: %i", right.fields.sign);

    }
    return false;
}

int
main (void)
{

  bool all_tests_pass = test_runner ();
  printf ("size of ieee float 64 bit: %lu\n", sizeof (ieee_float64));

  ieee_float64 first = {
      .number = 0.3
  };
  ieee_float64 second = {
      .number = 3 * 0.1
  };
  assertFloatEquals (first, second);

  if (all_tests_pass)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}