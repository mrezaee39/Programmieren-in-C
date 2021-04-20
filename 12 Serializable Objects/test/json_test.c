#include "12 Serializable Objects/json.h"
#include "unity.h"

JSON *json;

void
setUp(void)
{
    json = JSON_new();
}

void
tearDown(void)
{
    JSON_destroy(&json);
}



int
main(void)
{
    UNITY_BEGIN();

    return UNITY_END();
}