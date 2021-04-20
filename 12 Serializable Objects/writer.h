#ifndef PROGRAMMING_C_WRITER
#define PROGRAMMING_C_WRITER

typedef struct Writer Writer;

void
Writer_open(Writer *self);

void
Writer_write(Writer *self, const char *);

void
Writer_close(Writer *self);

void
Writer_destroy(Writer **self);

Writer *
newFileWriter(const char *path);

#endif