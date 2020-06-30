#include "route.h"
#include <stddef.h>
#include <stdlib.h>

enum {
    IP_BYTES = 4
};

static uint32_t
deserializeIPAndSaveEndPtr(const char *start, char **end);

static void
deserializeNetworkID(Route *route, const char *network_id_string);

Route
deserializeRoutingTableEntry(StringifiedRoute *route_strings) {
    Route route = {
            .network_id = {.ip = 0, .bitmask_length = 0},
            .gateway = 0
    };
    deserializeNetworkID(&route, route_strings->network_id);
    route.gateway = deserializeIP(route_strings->gateway);
    return route;
}

uint32_t
deserializeIP(const char *ip_string)
{
    char *end;
    uint32_t destination_ip = deserializeIPAndSaveEndPtr(ip_string, &end);
    return destination_ip;
}


void
deserializeNetworkID(Route *route, const char *network_id_string) {
    char *end;
    const char *start = network_id_string;
    route->network_id.ip = deserializeIPAndSaveEndPtr(start, &end);
    route->network_id.bitmask_length = strtoul(end + 1, NULL, 10);
}

uint32_t
deserializeIPAndSaveEndPtr(const char *start, char **end) {
    uint32_t ip = 0;
    for (int8_t index = IP_BYTES - 1; index >= 0; index--) {
        ip |= (strtoul(start, end, 10) << index * 8u);
        start = *end + 1;
    }
    return ip;
}