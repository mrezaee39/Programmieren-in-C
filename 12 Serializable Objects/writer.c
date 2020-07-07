#include "writer.h"
#include "writer_private.h"
#include <stddef.h>


void
Writer_open(Writer *self)
{
    self->open(self);
}

void
Writer_close(Writer *self)
{
    self->close(self);
}

void
Writer_write(Writer *self, const char *text)
{
    self->write(self, text);
}

void
Writer_destroy(Writer **self)
{
    (*self)->destroy(*self);
    *self = NULL;
}