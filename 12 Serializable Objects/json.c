#include "json.h"
#include <malloc.h>
#include <string.h>
#include "linked_list.h"
#include "writer.h"


JSON *
newJSON(void) {
    List *json = malloc(sizeof(List));
    json->node = NULL;
    return (JSON *) json;
}


static JSONEntry *
appendNewEntry(JSON *self, const char *key) {
    JSONEntry *entry = malloc(sizeof(JSONEntry));
    size_t key_length = strlen(key) + 1;
    entry->key = malloc(key_length);
    memcpy(entry->key, key, key_length);
    List_append((List *) self, entry);
    return entry;
}

JSONEntry *
JSON_addInteger(JSON *self, const char *key, long number) {
    JSONEntry *entry = appendNewEntry(self, key);
    entry->type = JSON_TYPE_INTEGER;
    entry->value.integer = number;
    return entry;
}

JSONEntry *
JSON_addFloat(JSON *self, const char *key, double number) {
    JSONEntry *entry = appendNewEntry(self, key);
    entry->type = JSON_TYPE_FLOATING_POINT;
    entry->value.floating_point = number;
    return entry;
}

JSONEntry *
JSON_addJSON(JSON *self, const char *key, const JSON *json) {
    JSONEntry *entry = appendNewEntry(self, key);
    entry->type = JSON_TYPE_JSON;
    entry->value.json = (JSON *) json;
    return entry;
}

JSONEntry *
JSON_get(JSON *self, const char *key) {
    LinkedListNode *current_node = ((List *) self)->node;
    if (current_node == NULL) {
        return NULL;
    }
    const char *current_key = ((JSONEntry *) current_node->data)->key;
    while (strcmp(current_key, key) != 0 && current_node->next != NULL)
    {
        current_node = current_node->next;
        current_key = ((JSONEntry *) current_node->data)->key;
    }
    if (strcmp(current_key, key) == 0)
    {
        return (JSONEntry *) current_node->data;
    }
    else
    {
        return NULL;
    }
}

bool
JSON_dump(JSON *self, Writer *writer)
{
    Writer_open(writer);
    Writer_write(writer, "{");
    Writer_close(writer);
    // to be continued...
}