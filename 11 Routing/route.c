#include "route.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    IP_BYTES = 4,
};



static void
serializeIP(char *string, uint32_t ip)
{
    uint8_t ip_array[IP_BYTES];
    for (uint8_t index = 0; index < 4; index++)
    {
        ip_array[index] = (0xffu & (ip >> 8u*index));
    }
    sprintf(string, "%i.%i.%i.%i",
            ip_array[3],
            ip_array[2],
            ip_array[1],
            ip_array[0]);
}

StringifiedRoute
serializeRoute(const Route *route)
{

    StringifiedRoute route_strings = {
            .network_id = "0.0.0.17/12"
    };
    /*
     *      0x801
     * & 0xff0000
     *   --------
     *          0
     *
     *    0x801
     * & 0xff00
     * --------
     *    0x800 -> cast to uint8_t  results in 0
     */
    serializeIP(route_strings.gateway, route->gateway);
    serializeIP(route_strings.network_id, route->network_id.ip);
    uint8_t network_id_length = strlen(route_strings.network_id);
    sprintf(route_strings.network_id+network_id_length,
            "/%i", route->network_id.bitmask_length);
    return route_strings;
}

static uint32_t
deserializeIPandSaveEndPtr(const char *ip_string, char **end)
{
    const char *start = ip_string;
    uint32_t ip = 0;
    for (uint8_t byte_number = 0; byte_number < IP_BYTES; byte_number++)
    {
        ip |= (strtoul(start, end, 10) << (IP_BYTES - byte_number - 1)*8u);
        start = *end+1;
    }
    return ip;
}

uint32_t
deserializeIP(const char *ip_string)
{
    char *end;
    uint32_t ip = deserializeIPandSaveEndPtr(ip_string, &end);
    return ip;
}

static void
deserializeNetworkID(Route *route, const char *network_id_string)
{
    char *end;
    route->network_id.ip = deserializeIPandSaveEndPtr(network_id_string, &end);
    route->network_id.bitmask_length = strtoul(end+1, NULL, 10);
}

Route
deserializeRoute(StringifiedRoute *route_strings)
{
    Route route;
    route.gateway = deserializeIP(route_strings->gateway);
    deserializeNetworkID(&route, route_strings->network_id);
    return route;
}