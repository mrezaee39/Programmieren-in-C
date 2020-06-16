#ifndef PROGRAMMING_C_MESSAGE_H
#define PROGRAMMING_C_MESSAGE_H

#include <stdint.h>
#include <stddef.h>

enum {
    MESSAGE_TYPE_GET = 'A',
    MESSAGE_TYPE_ACK = 'B',
    MESSAGE_TYPE_NACK = 'C',
    MESSAGE_TYPE_POST = 'D',
};

typedef struct Message Message;

struct Message
{
    const uint8_t *data;
    size_t size;
    uint16_t destination_address;
    uint8_t type;
};


void
send(Message message);

void
receiveMessage(void *data);



#endif
