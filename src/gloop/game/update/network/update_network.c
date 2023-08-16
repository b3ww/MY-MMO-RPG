/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** update_network
*/

#include "rpg.h"
#include "network.h"
#include <string.h>
#include <stdlib.h>
#include "tools.h"

static void free_read(net_t *net)
{
    if (net->to_read) {
        free(net->rdata);
        net->to_read = false;
        net->rdata = NULL;
    }
}

bool update_network(net_t *net)
{
    const void *data = NULL;
    sfPacket *packet;
    free_read(net);
    if (!sfSocketSelector_wait(net->selector, sfMilliseconds(1)))
        return false;
    if (sfSocketSelector_isTcpSocketReady(net->selector, net->socket)) {
        packet = sfPacket_create();
        if (sfTcpSocket_receivePacket(net->socket, packet) == sfSocketDone) {
            data = sfPacket_getData(packet);
            net->rdata = malloc(sfPacket_getDataSize(packet));
            memcpy(net->rdata, data, sfPacket_getDataSize(packet));
            net->to_read = true;
            sfPacket_destroy(packet);
        } else {
            my_putstr("Connection lost\n");
            sfPacket_destroy(packet);
            // return true;
        }
    }
    return false;
}
