#include "3 Building C Programs/test.h"
#include "3 Building C Programs/fibonacci.h"
#include "3 Building C Programs/fibonacci_test.h"

void
run_fibonacci_test(void)
{
    int fibonacci_sequence_length = 10;
    int sequence[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    char message[] = "Fibonacci number 0";
    for (int index = 0; index < fibonacci_sequence_length; index++)
    {
        message[17] = '0' + (char)index;
        assertEqualIntWithMessage(sequence[index], fibonacci(index), message);
    }

}