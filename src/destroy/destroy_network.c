/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** destroy_network
*/

#include "destroy.h"
#include "rpg.h"

void destroy_network(net_t *network)
{
    if (network == NULL)
        return;
    if (network->to_read == true)
        free(network->rdata);
    sfTcpSocket_disconnect(network->socket);
    sfTcpSocket_destroy(network->socket);
    sfSocketSelector_destroy(network->selector);
    free(network);
}
