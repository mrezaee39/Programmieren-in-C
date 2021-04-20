#include "12 Serializable Objects/json.h"
#include "unity.h"
#include <string.h>

enum {BUFFER_SIZE = 128};

JSON *json;
char buffer[BUFFER_SIZE];
size_t buffer_position;
Writer *writer = NULL;

void
Writer_write(Writer *self, const char *string)
{
    if (self == writer)
    {
        memcpy(buffer + buffer_position, string, strlen(string));
        buffer_position += strlen(string);
    }
}

void
setUp(void)
{
    json = JSON_new();
    memset(buffer, 0, BUFFER_SIZE);
    buffer_position = 0;
    writer = NULL;
}

void
tearDown(void)
{
    JSON_destroy(&json);
}

void
test_JSONisNULL(void)
{
    JSON_dump(NULL, NULL);
    TEST_ASSERT_EQUAL_STRING("{ }", buffer);
}

void
test_JSONisEmpty(void)
{
    JSON_dump(json, NULL);
    TEST_ASSERT_EQUAL_STRING("{ }", buffer);
}

void
test_addIntegerOne(void)
{
    JSON_addInteger(json, "", 1);
    JSON_dump(json, NULL);
    TEST_ASSERT_EQUAL_STRING("{ '': 1 }", buffer);
}

void
test_addIntegerTwo(void)
{
    JSON_addInteger(json, "", 2);
    JSON_dump(json, NULL);
    TEST_ASSERT_EQUAL_STRING("{ '': 2 }", buffer);
}

void
test_addFloatOnePointFive(void)
{
    JSON_addFloat(json, "", 1.5);
    JSON_dump(json, NULL);
    TEST_ASSERT_EQUAL_STRING("{ '': 1.500000 }", buffer);
}

void
test_addFloatOnePointTwo(void)
{
    JSON_addFloat(json, "", 1.2);
    JSON_dump(json, NULL);
    TEST_ASSERT_EQUAL_STRING("{ '': 1.200000 }", buffer);
}

void
test_checkForWriterArgument(void)
{
    writer = (Writer *) 1;
    JSON_addInteger(json, "", 1);
    JSON_dump(json, writer);
    TEST_ASSERT_EQUAL_STRING("{ '': 1 }", buffer);
}

void
test_checkForWriterArgumentWithFloat(void)
{
    writer = (Writer *) 1;
    JSON_addFloat(json, "", 1.5);
    JSON_dump(json, writer);
    TEST_ASSERT_EQUAL_STRING("{ '': 1.500000 }", buffer);
}



int
main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_JSONisNULL);
    RUN_TEST(test_addIntegerOne);
    RUN_TEST(test_JSONisEmpty);
    RUN_TEST(test_addIntegerTwo);
    RUN_TEST(test_addFloatOnePointFive);
    RUN_TEST(test_addFloatOnePointTwo);
    RUN_TEST(test_checkForWriterArgument);
    RUN_TEST(test_checkForWriterArgumentWithFloat);
    return UNITY_END();
}