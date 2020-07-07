#ifndef PROGRAMMING_C_WRITER_PRIVATE_H
#define PROGRAMMING_C_WRITER_PRIVATE_H

typedef struct Writer Writer;

struct Writer {
    void (*open)(Writer* self);
    void (*write)(Writer* self, const char*);
    void (*close)(Writer *self);
    void (*destroy)(Writer *self);
};

#endif //PROGRAMMING_C_WRITER_PRIVATE_H
