#ifndef PROGRAMMING_C_LINKED_LIST_H
#define PROGRAMMING_C_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

/**
 * The header contains some linked list
 * utilities. The solutions here are
 * heavily inspired from the linux
 * kernel but we do not copy their
 * heavy macro usage.
 */

typedef struct ListNode ListNode;
struct ListNode
{
    ListNode *previous;
    ListNode *next;
};

/**
 * Initializes the list head to refer to
 * itself.
 */
static inline void
List_init(ListNode *self)
{
    self->next = self;
    self->previous = self;
}

static inline void
List_insert(ListNode *self, ListNode *new)
{
    new->next = self->next;
    new->previous = self;
    self->next = new;
}

static inline ListNode *
List_getLastNode(ListNode *self)
{
    ListNode *current = self;
    for(; current->next != self; current = current->next)
        ;
    return self;
}

#endif //PROGRAMMING_C_LINKED_LIST_H
