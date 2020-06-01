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
            .data = data_A
    };

    Matrix B = {
            .columns = 2,
            .rows = 2,
            .data = data_B
    };

    bool passed = assertEqualMatrix(A, B);
    if (passed)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}