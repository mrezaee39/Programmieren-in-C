#include "network_layer.h"
#include "message.h"

int
main(void)
{
    uint8_t frame[] = {
            0x00,
            0x01, 0x02,
            0x03, 0x04,
            0x05,
            MESSAGE_TYPE_ACK, 'f', 'g',
            'h', 'm',
    };
    Message m = {
            .data = frame+7,
            .destination_address = 0x0201,
            .size = 5,
            .type = MESSAGE_TYPE_ACK,
    };
    send(m);
    sendFrame(frame);
}

