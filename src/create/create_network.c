/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** create_network
*/

#include <stdlib.h>
#include "rpg.h"
#include "network.h"

net_t *create_network(sfIpAddress ip, uss_t port)
{
    net_t *network = malloc(sizeof(net_t));

    network->socket = sfTcpSocket_create();
    if (sfTcpSocket_connect(network->socket, ip, port, sfSeconds(5))
    != sfSocketDone) {
        sfTcpSocket_destroy(network->socket);
        free(network);
        return NULL;
    }
    network->to_read = false;
    network->to_send = false;
    network->sdata = NULL;
    network->rdata = NULL;
    network->selector = sfSocketSelector_create();
    sfSocketSelector_addTcpSocket(network->selector, network->socket);
    sfTcpSocket_setBlocking(network->socket, sfFalse);
    return network;
}
