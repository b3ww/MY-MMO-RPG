/*
** EPITECH PROJECT, 2023
** MMOPRG_ONLINE [SSH]
** File description:
** selector
*/

#include "share.h"
#include "wnetcsfml.h"
#include <string.h>

bool selector_is_ready(main_net_t *net)
{
    if (!net->listener) {
        WLOG("Impossible de créer le listener\n", net->log_file);
        return false;
    }
    if (sfTcpListener_listen(net->listener, net->listen_port,
    net->listen_address) != sfSocketDone) {
        WLOG("Erreur de la mise en écoute du listener\n", net->log_file);
        return false;
    }
    return true;
}

static void delete_client(main_net_t *net, sfTcpSocket *client_socket, int *i)
{
    disconnect_player_t err;

    WLOG("client déconnecté\n", net->log_file);
    sfSocketSelector_removeTcpSocket(net->selector, client_socket);
    sfTcpSocket_destroy(client_socket);
    err = dc_player(net, &net->clients[*i], "He want to stop game");
    send_to_all(net, &err);
    (*i)--;
}

void selector_receive(main_net_t *net, int *i)
{
    sfTcpSocket *client_socket = net->clients[*i].socket;
    sfPacket *packet = NULL;

    if (net->clients[*i].to_read)
        free(net->clients[*i].rdata);
    if (sfSocketSelector_isTcpSocketReady(net->selector, client_socket)) {
        packet = sfPacket_create();
        if (sfTcpSocket_receivePacket(client_socket, packet) == sfSocketDone) {
            net->clients[*i].rdata = wmcpy(sfPacket_getData(packet),
            sfPacket_getDataSize(packet));
            net->clients[*i].to_read = true;
        sfPacket_destroy(packet);
        } else
            delete_client(net, client_socket, i);
    }
}

void send_to_client(client_t *client, void *to_send)
{
    sfPacket *packet = sfPacket_create();
    size_t size = get_type_size(to_send);

    if (!size) {
        sfPacket_destroy(packet);
        return;
    }
    sfPacket_append(packet, to_send, size);
    sfTcpSocket_sendPacket(client->socket, packet);
    sfPacket_destroy(packet);
}
