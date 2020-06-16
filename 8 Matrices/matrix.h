#ifndef PROGRAMMING_C_MATRIX_H
#define PROGRAMMING_C_MATRIX_H

#include <stddef.h>
#include <stdbool.h>

typedef struct Matrix Matrix;

struct Matrix {
    size_t rows;
    size_t columns;
    float *data;
};

bool
assertEqualMatrix(Matrix expected, Matrix actual);

bool
assertUnequalMatrix(Matrix expected, Matrix actual);

#endif //PROGRAMMING_C_MATRIX_H
