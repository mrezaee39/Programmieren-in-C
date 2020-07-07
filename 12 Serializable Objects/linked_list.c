#include "linked_list.h"
#include "malloc.h"

bool
List_append(List *self, void *data) {
    LinkedListNode *node = self->node;
    if (node != NULL) {
        for (; node->next != NULL; node = node->next) {}
    }
    node = malloc(sizeof(LinkedListNode));
    if (node == NULL) {
        return false;
    }
    node->data = data;
    node->next = NULL;
    self->node = node;
    return true;
}