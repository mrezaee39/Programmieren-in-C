#include "unity.h"

struct DictEntry
{
    char *key;
    void *data;
};

typedef struct DictEntry DictEntry;
static DictEntry entry = {
        .data = NULL,
        .key = NULL,
};

void
setUp(void)
{
    entry.data = NULL;
    entry.key = NULL;
}

void
tearDown(void)
{

}

void
test_dict(void)
{
    // call function that changes entry
    entry.key = "our key";
    TEST_ASSERT_EQUAL_PTR(NULL, entry.data);
    TEST_ASSERT_EQUAL_STRING("our key", entry.key);
}

void
test_my_first_test(void)
{
    char * first = "hello world";
    char *second = "Hello World";
    TEST_ASSERT_EQUAL_STRING(first, second);
}

void
test_my_second_test(void)
{
    int a = 1;
    int b = 2;
    TEST_ASSERT_EQUAL_HEX32(a, b);
}

void
test_array(void)
{
    int a[] = {1, 2};
    int b[] = {1, 3};
    TEST_ASSERT_EQUAL_INT32_ARRAY(a, b, 2);
}

int
main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_my_first_test);
    RUN_TEST(test_my_second_test);
    RUN_TEST(test_array);
    RUN_TEST(test_dict);
    return UNITY_END();
}