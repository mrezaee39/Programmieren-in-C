#ifndef PROGRAMMING_C_EXERCISE_H
#define PROGRAMMING_C_EXERCISE_H

typedef struct Vector Vector;

struct Vector {
    const unsigned int length;
    const float *data;
};

float
dot (Vector left, Vector right);

float
sum (Vector vector);

Vector
multiply (Vector left, Vector right, float *out_buffer);

#endif //PROGRAMMING_C_EXERCISE_H