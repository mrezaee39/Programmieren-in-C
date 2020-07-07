#ifndef PROGRAMMING_C_LINKED_LIST_H
#define PROGRAMMING_C_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct List List;
typedef struct LinkedListNode LinkedListNode;


struct LinkedListNode {
    void *data;
    LinkedListNode *next;
};

struct List
{
    LinkedListNode *node;
    size_t size;
};

bool
List_append(List *self, void *data);

#endif //PROGRAMMING_C_LINKED_LIST_H
