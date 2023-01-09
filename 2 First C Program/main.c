#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*************************
 * Function Declarations *
 *************************/
void
checkThatStringIsHelloWorld(const char *string);

void
checkForIncrementallyIncreasingSequence(int *sequence);

int
sumNumbersUpTo(int to);

void
printCheckResult(bool condition);

/******************************
 * Your exercise starts here!
 *
 * The exercise consists of a sequence
 * of checks. Your task is to adjust
 * the corresponding code to make each
 * check pass. Each check will print
 * either "Wrong" or "Correct"
 * on your terminal. The check has
 * passed if it printed "Correct".
 *
 * You can safely ignore the function
 * declarations above and function
 * definitions below the main function.
 *
 * Don't forget to recompile your
 * program after any changes!
 *******************************/
int
main(void)
{
    /// 1. Initialize the array with the correct "Hello, World!" string
    char helloWorld[20] = "Hello, World!";
    checkThatStringIsHelloWorld(helloWorld);
    int counter_value=0;
    printf("%d ", counter_value);
    for (; counter_value < 256; counter_value++) {
    }

    //printf("%i ", UINT_MAX);

    double should_reach_03 = 0;
    should_reach_03 += 0.1;
    printf("%f\n",should_reach_03);
    //assertEqualDouble(0.1, should_reach_03);
    should_reach_03 += 0.1;
    printf("\n%f\n",should_reach_03);
   //assertEqualDouble(0.2, 0.2);
    should_reach_03 += 0.1;
    printf("\n%f\n",should_reach_03);
//name[]={'H',......,'\0'};
    //char name[] ="How long is this text?";
    //printf("\n\nsizeofint=%d\n\n",sizeof(UINT_MAX));

    // 2. adjust the values of firstCondition and secondCondition to make the check pass
    puts("2. Entering else if statement check...");
    bool firstCondition = false;
    bool secondCondition = false;
    if (firstCondition)
    {
        puts("Wrong\n");
    }
    else if (!secondCondition)
    {
        puts("Correct\n");
    }
    else
    {
        puts("Wrong\n");
    }

    // 3. Fill the array numbers with the numbers from 0 to 9
    int numbers[10];
    for (int replace_this_counter = 0; replace_this_counter < 10; replace_this_counter++)
    {
        numbers[replace_this_counter] = replace_this_counter;
    }
    checkForIncrementallyIncreasingSequence(numbers);

    /*  4.
     *  change the value of switch_case_number
     *  and add one line to one of the cases
     *  so that the check passes (prints "Correct")
     */
    int switch_case_number = 1;
    puts("4. Entering switch case check...");
    bool switch_case_correct = false;
    switch(switch_case_number)
    {
        case 0:
            break;
        case 1:
            switch_case_correct = true;
            break;
        case 2:
            switch_case_correct = false;
        default:
            break;
    }
    printCheckResult(switch_case_correct);

    /* 5.
     * In the task below the boolean expression in the while
     * loop is messed up. Correct it to make the test pass.
     * Assume you have no knowledge about the array `set_of_numbers`.
     */
    puts("5. Entering while loop check...");
    int set_of_numbers[] =  {0, 4, 8, 1, 9, 5, 6, 2, 3};
    int index = 0;
    int first_number_greater4_smaller7 = set_of_numbers[index];

    while(!(first_number_greater4_smaller7 > 4 && first_number_greater4_smaller7 < 8))
    {
        index++;
        first_number_greater4_smaller7 = set_of_numbers[index];
    }
    printCheckResult(first_number_greater4_smaller7 == 5);

    /* 6.
     * In this task we want to perform a calculation
     * several times for different variables.
     * This would lead to the for loop below
     * being repeated several times. Instead
     * of copy-pasting it is a good idea
     * to restructure the code and move that
     * calculation to a function. In line 142
     * you'll find an empty function definition.
     * Move the algorithm there to make the checks
     * pass.
     *
     * You'll have to slightly adjust the code fragment.
     */

    puts("6. Entering function call check... (will perform two checks)");


    int result = sumNumbersUpTo(50);
    printCheckResult(result == 1275);

    result = sumNumbersUpTo(30);
    printCheckResult(result == 465);

    return 0;
}


int
sumNumbersUpTo(int to)
{
  int sum = 0;
  for (; to > 0; to--)
    {
      sum += to;
    }
  return sum;
}


/************************
 * Function Definitions *
 ************************/
void
checkThatStringIsHelloWorld(const char *string)
{
    puts("1. Checking Hello World...");
    char hello[] = "Hello, World!";
    printCheckResult(strcmp(string, hello) == 0);
}

void
checkForIncrementallyIncreasingSequence(int *sequence)
{
    bool sequence_correct = true;
    puts("3. Checking that Sequence is incrementally increasing...");
    for (int counter = 0; counter < 10 & sequence_correct; counter++)
    {
        sequence_correct = (sequence[counter] == counter);
    }
    printCheckResult(sequence_correct);
}

void
printCheckResult(bool condition)
{
    if (condition)
    {
        puts("Correct\n");
    }
    else
    {
        puts("Wrong\n");
    }
}
