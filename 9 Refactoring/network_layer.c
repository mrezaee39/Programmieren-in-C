#include "network_layer.h"
#include <string.h>
#include <stdio.h>

static uint8_t
getSourceAddressSize(uint8_t addressing_format)
{
    uint8_t offset = 2;
    if ((addressing_format & 1) == ADDRESSING_FORMAT_SOURCE64)
    {
        offset += 6;
    }
    return offset;
}

static uint8_t
getDestinationAddressSize(uint8_t addressing_format)
{
    uint8_t offset = 2;
    if ((addressing_format & 2) == ADDRESSING_FORMAT_DESTINATION64)
    {
        offset += 6;
    }
    return offset;
}

static uint8_t
getPayloadOffset(uint8_t addressing_format)
{
    uint8_t offset = 1 +
            getDestinationAddressSize(addressing_format) +
            getSourceAddressSize(addressing_format);
    return offset;
}

static void
printDestinationAddress(const uint8_t *frame, uint8_t addressing_format)
{
    puts("Destination Address");
    uint8_t offset = 1;
    for (int i = offset; i < offset + getDestinationAddressSize(addressing_format); i++)
    {
        printf("0x%x ", frame[i]);
    }
    printf("\n");
}

static void
printSourceAddress(const uint8_t *frame, uint8_t addressing_format)
{
    puts("Source Address:");
    uint8_t offset = 1 + getDestinationAddressSize(addressing_format);
    for (int i = offset; i < offset + getSourceAddressSize(addressing_format); i++)
    {
        printf("0x%x ", frame[i]);
    }
    printf("\n");
}

void
sendFrame(const uint8_t *frame)
{
    uint8_t addressing_format = frame[0];
    uint8_t payload_offset = getPayloadOffset(addressing_format);
    uint8_t payload_size = frame[payload_offset];
    char payload[payload_size+2];
    payload[payload_size+1] = '\0';
    payload[payload_size] = '\n';
    printDestinationAddress(frame, addressing_format);
    printSourceAddress(frame, addressing_format);
    memcpy(payload, frame+payload_offset+1, payload_size);
    puts("Payload:");
    puts(payload);
}