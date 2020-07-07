#include "unity.h"

void
setUp(void)
{

}

void
tearDown(void)
{

}

void
test_my_first_test(void)
{
    TEST_FAIL_MESSAGE("this test failed");
}

int
main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_my_first_test, 18);
    return UNITY_END();
}