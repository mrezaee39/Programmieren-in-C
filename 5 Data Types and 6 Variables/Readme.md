# Data Types and Variables

In the last exercise you saw that floating point numbers sometimes
behave a little different than what one might expect.
This time you will take a closer look at how they differ.
Use your knowledge about structs and unions from the lectures
to create a custom float type `ieee_float64` which allows you
to inspect the three parts the decimal numbers are built from
seperately. In the file `exercise.c` you will find again a bunch
of tests that will check whether or not your implementation is correct.
Since the definition of the data type is missing the code will not
compile before you added your own definition.
Hint: You will have to utilize the following syntax
```c
struct myStructWithBitfields
{
    int integer_type_with_3bit : 3;
    int integer_type_with_5bit : 5;
};
```

To get a nice representation of the numbers on the command line
write a function that compares two numbers of type `double`
and prints the parts that are different to the command line.
Then repeat the last experiment from last week, where we found that
sometimes
```
3*0.1 != 0.3
```
You can use the `main.c` file for the corresponding code.
