#include <stdio.h>
#include <test_util/test.h>
#include "matrix.h"

int
main(void)
{
    float data_A[2][2] = {
            {1, 0},
            {0, 1}
    };
    float data_B[2][2] = {
            {1, 0},
            {2, 1}
    };

    Matrix A = {
            .columns = 2,
            .rows = 2,
            .data = (float *)data_A
    };

    Matrix B = {
            .columns = 2,
            .rows = 2,
            .data = (float *)data_B
    };

    Matrix C = {
            .columns = 2,
            .rows = 2,
            .data = (float *)data_A
    };
    Matrix D = {
            .columns = 3,
            .rows = 100,
            .data = (float *)data_A
    };

    TestSuite *suite = createTestSuite(3);
    addTestResult(suite, assertUnequalMatrix(A, B)); // supposed to fail right now
    addTestResult(suite, assertEqualMatrix(A, C)); // supposed to pass
    addTestResult(suite, assertUnequalMatrix(D, A));
    return evaluateTestSuite(suite);
}