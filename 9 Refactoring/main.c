#include "network_layer.h"

int
main(void)
{
    uint8_t frame[] = {
            0x00,
            0x01, 0x02,
            0x03, 0x04,
            0x05,
            'A', 'B', 'C',
            'a', 'b',
    };
    sendFrame(frame);
}

