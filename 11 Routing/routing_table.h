#ifndef PROGRAMMING_C_ROUTING_TABLE_H
#define PROGRAMMING_C_ROUTING_TABLE_H

#include <stdint.h>
#include <stddef.h>

typedef struct StringifiedRoute StringifiedRoute;
typedef struct RoutingTable RoutingTable;


struct RoutingTable
{
    size_t size;
    StringifiedRoute *entries;
};


uint32_t
resolveRouteToGateway(const char *destination, const RoutingTable *table);

#endif //PROGRAMMING_C_ROUTING_TABLE_H
