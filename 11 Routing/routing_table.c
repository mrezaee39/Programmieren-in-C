#include "routing_table.h"
#include "route.h"
#include <stdbool.h>

typedef struct Match
{
    int8_t score;
    Route route;
    bool match;
} Match;

static Match
findBestMatch(uint32_t destination, const RoutingTable *table);

uint32_t
resolveRouteToGateway(const char *destination, const RoutingTable *table)
{
    uint32_t destination_ip = deserializeIP(destination);
    Match match = findBestMatch(destination_ip, table);
    return match.route.gateway;
}

static void
updateOnImprovement(Match *current, uint32_t destination, StringifiedRoute *route_strings);

Match
findBestMatch(uint32_t destination, const RoutingTable *table)
{
    Match best = {
            .score = -1,
            .match = false,
    };
    for (uint8_t index = 0; index < table->size; index++)
    {
        updateOnImprovement(&best, destination, &table->entries[index]);
    }
    return best;
}

uint32_t
getBitMask(uint8_t length)
{
    uint32_t mask = 0;
    for (int8_t bit_number=31; bit_number > 31 - length; bit_number--)
    {
        mask |= (1u << (uint8_t )bit_number);
    }
    return mask;
}

Match
calculateMatch(uint32_t destination, StringifiedRoute *route_strings)
{
    Route route = deserializeRoute(route_strings);
    Match match;
    match.route = route;
    if (route.network_id.ip == 0 && route.network_id.bitmask_length == 0)
    {
        match.score = 0;
        match.match = true;
    }
    else
    {
        match.score = route.network_id.bitmask_length;
        uint32_t bitmask = getBitMask(route.network_id.bitmask_length);
        uint32_t masked_destination = destination & bitmask;
        uint32_t masked_network_id = route.network_id.ip & bitmask;
        match.match = masked_destination == masked_network_id;
    }
    return match;
}

static void
updateOnImprovement(Match *current, uint32_t destination, StringifiedRoute *route_strings)
{
    Match next = calculateMatch(destination, route_strings);
    if (next.match && next.score > current->score)
    {
        *current = next;
    }
}
