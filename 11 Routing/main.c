#include "routing_table.h"
#include "route.h"
#include <stdio.h>
#include "test_util/test.h"

StringifiedRoute routing_table_entries[4] = {
        {
                .network_id = "243.154.33.0/24",
                .gateway = "243.154.33.1",
        },
        {
                .network_id = "243.154.0.0/16",
                .gateway = "243.154.0.100",
        },
        {
                .network_id = "0.0.0.0/0",
                .gateway = "192.168.0.100",
        },
        {
                .network_id = "192.168.208.0/19",
                .gateway = "192.168.192.100"
        }
};

RoutingTable table = {
        .size = 4,
        .entries = routing_table_entries
};

int
main(void)
{
    Route route = {
            .gateway = 256*8+1,
            .network_id = {
                    .bitmask_length = 12,
                    .ip = 256
            }
    };
    StringifiedRoute route_strings = serializeRoute(&route);
    printf("network id: %s, gateway: %s\n",
            route_strings.network_id, route_strings.gateway);
    assertEqualIntHex(route.gateway, deserializeIP(route_strings.gateway));

    route = deserializeRoute(&route_strings);
    printf("network id: %x, bitmask length: %u, gateway: %x\n",
           route.network_id.ip, route.network_id.bitmask_length,
           route.gateway);


    char *destination = "243.154.33.55";
    route = deserializeRoute(table.entries+0);
    assertEqualIntHex(route.gateway, resolveRouteToGateway(destination, &table));
    destination = "243.154.2.15";

    route = deserializeRoute(table.entries+1);
    assertEqualIntHex(route.gateway, resolveRouteToGateway(destination, &table));

    route = deserializeRoute(table.entries+2);
    destination = "8.8.8.8";
    assertEqualIntHex(route.gateway, resolveRouteToGateway(destination, &table));
}