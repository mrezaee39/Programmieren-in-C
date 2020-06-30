#include "routing_table.h"
#include "route.h"
#include <string.h>
#include <stdbool.h>


typedef struct MatchResult
{
    bool match;
    int8_t match_score;
    Route route;
} MatchResult;

static uint32_t
getBitmask(uint8_t bitmask_size);

static MatchResult
matchDestinationToRoute(uint32_t destination, Route route);

static void
updateMatchOnImprovement(MatchResult *current_match, const MatchResult *new_match);

static MatchResult
findBestMatchForDestination(uint32_t destination, const RoutingTable *table);


uint32_t
resolveRouteToGateway(const char *destination, const RoutingTable *table)
{
    uint32_t destination_ip = deserializeIP(destination);
    MatchResult match = findBestMatchForDestination(destination_ip, table);
    return match.route.gateway;
}

MatchResult
findBestMatchForDestination(uint32_t destination, const RoutingTable *table)
{
    MatchResult best_match = {.match=false, .match_score=-1};
    for (size_t index=0; index < table->size; index++)
    {
        Route tmp_route = deserializeRoutingTableEntry(table->entries+index);
        MatchResult tmp_match = matchDestinationToRoute(destination, tmp_route);
        updateMatchOnImprovement(&best_match, &tmp_match);
    }
    return best_match;
}


MatchResult
matchDestinationToRoute(uint32_t destination, Route route)
{
    MatchResult result;
    if (route.network_id.ip == 0 && route.network_id.bitmask_length == 0)
    {
        result.match = true;
        result.match_score = 0;
    }
    else
    {
        uint32_t bitmask = getBitmask(route.network_id.bitmask_length);
        uint32_t masked_network_ip = bitmask & route.network_id.ip;
        uint32_t masked_destination = bitmask & destination;
        result.match = masked_destination == masked_network_ip;
        result.match_score = route.network_id.bitmask_length;
        result.route = route;
    }
    return result;
}


static uint32_t
getBitmask(uint8_t bitmask_size)
{
    uint32_t bitmask = 0u;
    for (int8_t bit_number=31; bit_number > 31 - bitmask_size; bit_number--)
    {
        bitmask ^= (1u << (uint8_t)bit_number);
    }
    return bitmask;
}


void
updateMatchOnImprovement(MatchResult *current_match, const MatchResult *const new_match)
{
    if (new_match->match && new_match->match_score > current_match->match_score)
    {
        *current_match = *new_match;
    }
}

