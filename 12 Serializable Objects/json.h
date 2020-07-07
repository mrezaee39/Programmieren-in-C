#ifndef PROGRAMMING_C_JSON_H
#define PROGRAMMING_C_JSON_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct JSON JSON;
typedef struct JSONEntry JSONEntry;

struct JSONEntry {
    uint8_t type;
    char *key;
    union {
        long integer;
        double floating_point;
        JSON *json;
    } value;
};


JSON*
JSON_new(void);

JSONEntry *
JSON_addInteger(JSON *self, const char *key, long number);

JSONEntry *
JSON_addFloat(JSON *self, const char *key, double number);

JSONEntry *
JSON_addJSON(JSON *self, const char *key, const JSON *json);

JSONEntry *
JSON_addEntry(JSON *self, JSONEntry *entry);

JSONEntry *
JSON_get(JSON *self, const char *key);

bool
JSON_dump(JSON *self, const char *path);


#endif //PROGRAMMING_C_JSON_H
