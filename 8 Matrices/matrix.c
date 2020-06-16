#include <stdbool.h>
#include "matrix.h"

static bool
matrixDimensionsAreEqual(const Matrix *left, const Matrix *right) {
    return (left->columns == right->columns && left->rows == right->rows);
}

static bool
matrixDataIsEqual(const Matrix *expected, const Matrix *actual) {
    size_t total_number_of_coefficients = expected->columns * expected->rows;

    for (size_t index = 0; index < total_number_of_coefficients; index++)
    {
        if (expected->data[index] != actual->data[index])
        {
            return false;
        }
    }
    return true;
}

bool
assertEqualMatrix(Matrix expected, Matrix actual) {
    return matrixDimensionsAreEqual(&expected, &actual) &&
           matrixDataIsEqual(&expected, &actual);
}

bool
assertUnequalMatrix(Matrix expected, Matrix actual) {
    return !assertEqualMatrix(expected, actual);
}