#include "message.h"
#include "network_layer.h"
#include <string.h>

const uint8_t SOURCE_ADDRESS_H = 0x04;
const uint8_t SOURCE_ADDRESS_L = 0x03;

enum {
    ADDRESS_FORMAT_OFFSET = 0,
    DESTINATION_ADDRESS_HIGH_BYTE_OFFSET = 1,
    DESTINATION_ADDRESS_LOW_BYTE_OFFSET = 2,
    SOURCE_ADDRESS_HIGH_BYTE_OFFSET = 3,
    SOURCE_ADDRESS_LOW_BYTE_OFFSET = 4,
    MESSAGE_SIZE_OFFSET = 5,
    MESSAGE_TYPE_OFFSET = 6,
    PAYLOAD_START_OFFSET = 7,
};

void
send(Message message)
{
    uint8_t raw_frame[7 + message.size];
    raw_frame[SOURCE_ADDRESS_HIGH_BYTE_OFFSET] = SOURCE_ADDRESS_H;
    raw_frame[SOURCE_ADDRESS_LOW_BYTE_OFFSET] = SOURCE_ADDRESS_L;
    raw_frame[ADDRESS_FORMAT_OFFSET] = (ADDRESSING_FORMAT_SOURCE16 | ADDRESSING_FORMAT_DESTINATION16);
    raw_frame[DESTINATION_ADDRESS_HIGH_BYTE_OFFSET] = (uint8_t)(message.destination_address >> 8);
    raw_frame[DESTINATION_ADDRESS_LOW_BYTE_OFFSET] = (uint8_t)(message.destination_address);
    raw_frame[MESSAGE_SIZE_OFFSET] = message.size;
    raw_frame[MESSAGE_TYPE_OFFSET] = message.type;
    memcpy(raw_frame + PAYLOAD_START_OFFSET, message.data, message.size);
    sendFrame(raw_frame);
}