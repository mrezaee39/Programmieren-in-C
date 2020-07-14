#include "json.h"
#include <malloc.h>
#include <string.h>
#include "linked_list.h"
#include "writer.h"

typedef struct JSONNode
{
    ListNode list;
    JSONEntry entry;
} JSONNode;

JSON *
JSON_new(void)
{
    JSONNode *json = malloc(sizeof(JSONNode));
    List_init(&json->list);
    json->entry.key = NULL;
    return (JSON *) json;
}


static JSONEntry *
appendNewEntry(JSON *self, const char *key)
{
    JSONNode *new;
    if (((JSONNode *) self)->entry.key == NULL)
    {
        new = (JSONNode *) self;
    }
    else
    {
        new = (JSONNode *) JSON_new();
    }
    size_t key_length = strlen(key);
    new->entry.key = malloc(key_length);
    memcpy(new->entry.key, key, key_length);
    JSONNode *last = (JSONNode *) List_getLastNode((ListNode *) self);
    List_insert((ListNode *) last, (ListNode *) new);
    return &new->entry;
}

JSONEntry *
JSON_addInteger(JSON *self, const char *key, long number)
{
    JSONEntry *entry = appendNewEntry(self, key);
    entry->type = JSON_TYPE_INTEGER;
    entry->value.integer = number;
    return entry;
}

JSONEntry *
JSON_addFloat(JSON *self, const char *key, double number)
{
    JSONEntry *entry = appendNewEntry(self, key);
    entry->type = JSON_TYPE_FLOATING_POINT;
    entry->value.floating_point = number;
    return entry;
}

JSONEntry *
JSON_addJSON(JSON *self, const char *key, const JSON *json)
{
    JSONEntry *entry = appendNewEntry(self, key);
    entry->type = JSON_TYPE_JSON;
    entry->value.json = (JSON *) json;
    return entry;
}


JSONEntry *
JSON_get(JSON *self, const char *key)
{
    ListNode *current_node = (ListNode *) self;
    bool search_hit = false;
    for (;
            current_node->next != current_node
            && !search_hit;
            current_node = current_node->next)
    {
        search_hit = (strcmp(key, ((JSONNode *) current_node)->entry.key) == 0);
    }
    if (!search_hit)
    {
        return NULL;
    }
    return &((JSONNode *) current_node)->entry;
}

void
JSON_destroy(JSON **self)
{
    ListNode *last = List_getLastNode((ListNode *) *self);
    while (last->previous != (ListNode *)*self)
    {
        last = last->previous;
        free(last->next);
    }
    free(last);
    *self = NULL;
}

void
JSON_dump(JSON *self, Writer *writer)
{
    Writer_open(writer);
    Writer_write(writer, "{");
    if (self != NULL)
    {
        ListNode *current_node = (ListNode *) self;
        do {
            Writer_write(NULL, " 'my special number': 0 ");
            current_node = current_node->next;
        } while (current_node != (ListNode *)self);
    }

    Writer_write(writer, "}");
    Writer_close(writer);
    // to be continued...
}