#ifndef PROGRAMMING_C_NETWORK_LAYER_H
#define PROGRAMMING_C_NETWORK_LAYER_H

#include <stdint.h>

enum {
    ADDRESSING_FORMAT_SOURCE16 = 0,
    ADDRESSING_FORMAT_SOURCE64 = 1,
    ADDRESSING_FORMAT_DESTINATION16 = 0,
    ADDRESSING_FORMAT_DESTINATION64 = 2,
};

/**
 * A frame has the following layout
 * |Byte | Description             |
 * |-----+-------------------------|
 * |    1| Addressing Format       |
 * |  2-8| Destination Address     |
 * |  2-8| Source Address          |
 * |    2| Payload Size            |
 * |0-120| Payload                 |
 *
 */

void
sendFrame(const uint8_t *frame);

#endif //PROGRAMMING_C_NETWORK_LAYER_H
