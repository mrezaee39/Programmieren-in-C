#include "12 Serializable Objects/json.h"
#include "12 Serializable Objects/writer.h"
#include "string.h"
#include "unity.h"


enum {TEXT_BUFFER_SIZE = 128};
char text_buffer[TEXT_BUFFER_SIZE];
int current_buffer_position = 0;
JSON *json;

void
Writer_open(Writer *self){}

void
Writer_write(Writer *self, const char *text)
{
    memcpy((text_buffer + current_buffer_position), text, strlen(text));
    current_buffer_position += strlen(text);
}

void
Writer_close(Writer *self)
{
}

void
setUp(void)
{
    for (int index = 0; index < TEXT_BUFFER_SIZE; index++)
    {
        text_buffer[index] = 0;
    }
    json = JSON_new();
    current_buffer_position = 0;
}

void
tearDown(void)
{
    JSON_destroy(&json);
}

void
test_emptyJSON(void)
{
    JSON_dump(NULL, NULL);
    TEST_ASSERT_EQUAL_STRING("{}", text_buffer);
}

void
test_writeZero(void)
{
    const char key[] = "my special number";
    JSON_addInteger(json, key, 0);
    JSON_dump(json, NULL);
    TEST_ASSERT_EQUAL_STRING("{ 'my special number': 0 }", text_buffer);
}

int
main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_emptyJSON);
    RUN_TEST(test_writeZero);
    return UNITY_END();
}