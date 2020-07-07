#include "linked_list.h"
#include "malloc.h"

bool
List_append(List *self, void *data) {
    LinkedListNode *node = self->node;
    if (node != NULL) {
        for (; node->next != NULL; node = node->next) {}
        node->next = malloc(sizeof(LinkedListNode));
        node = node->next;
        if (node == NULL)
        {
            return false;
        }
    }
    else {
        self->node = malloc(sizeof(LinkedListNode));
        node = self->node;
    }
    node->data = data;
    node->next = NULL;

    return true;
}