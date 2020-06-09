#include "exercise.h"
#include "test_util/test.h"

int
main(void)
{
    /*
     * The function below is supposed to
     * manipulate the state of the global
     * variable `exercise7` and set the
     * `passed` member to false.
     */
    TestSuite *exercise7 = createTestSuite(5);
    test_Failing(exercise7);
    addPassResult(exercise7);
    addFailResult(exercise7);
    addPassResult(exercise7);
    return evaluateTestSuite(exercise7);
}