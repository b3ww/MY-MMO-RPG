/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** send_to_server
*/

#include "rpg.h"
#include "network.h"
#include "tools.h"
#include <stdlib.h>

void send_to_server(net_t *net, void *to_send)
{
    sfPacket *packet;
    size_t size = get_type_size(to_send);

    if (net == NULL)
        return;
    if (!size) {
        my_putstr("Unknow type to send\n");
        return;
    }
    packet = sfPacket_create();
    sfPacket_append(packet, to_send, size);
    sfTcpSocket_sendPacket(net->socket, packet);
    sfPacket_destroy(packet);
    net->to_send = false;
}
