#include "writer.h"
#include "writer_private.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct FileWriter
{
    Writer writer;
    char *path;
    FILE *file;
};

static void
open(Writer *self)
{
    struct FileWriter *writer = (struct FileWriter*) self;
    writer->file = fopen(writer->path, "w");
}

static void
write(Writer *self, const char *string)
{
    struct FileWriter *writer = (struct FileWriter*) self;
    fputs(string, writer->file);
}

static void
close(Writer *self)
{
    struct FileWriter *writer = (struct FileWriter*) self;
    fclose(writer->file);
}

static void
destroy(Writer *self)
{
    struct FileWriter *writer = (struct FileWriter*) self;
    free(writer->path);
    free(writer);
}

Writer *
newFileWriter(const char *path)
{
    struct FileWriter *writer = malloc(sizeof(struct FileWriter));
    size_t path_length = strlen(path) + 1;
    char *path_copy = malloc(path_length);
    memcpy(path_copy, path, path_length);
    writer->writer.write = write;
    writer->writer.open = open;
    writer->writer.close = close;
    writer->writer.destroy = destroy;
}