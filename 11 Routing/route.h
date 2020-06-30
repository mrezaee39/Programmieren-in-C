#ifndef PROGRAMMING_C_ROUTE_H
#define PROGRAMMING_C_ROUTE_H

#include <stdint.h>

enum
{
    NETWORK_ID_STRING_LENGTH = 19,
    IP_STRING_LENGTH = 16,
};

typedef struct Route Route;
typedef struct StringifiedRoute StringifiedRoute;


struct Route {
    struct {
        uint32_t ip;
        uint8_t bitmask_length;
    } network_id;
    uint32_t gateway;
};


struct StringifiedRoute
{
    char network_id[NETWORK_ID_STRING_LENGTH];
    char gateway[IP_STRING_LENGTH];
};


Route
deserializeRoutingTableEntry(StringifiedRoute *route);

uint32_t
deserializeIP(const char* ip_string);

#endif //PROGRAMMING_C_ROUTE_H
