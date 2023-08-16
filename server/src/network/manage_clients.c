/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski [SSH: 193.70.40.62]
** File description:
** manage_clients
*/

#include "wnetcsfml.h"
#include "tools.h"

static void less_client(main_net_t *net, int i)
{
    free(net->clients[i].players_data);
    for (int j = i; j < net->num_clients; j++)
        net->clients[j] = net->clients[j + 1];
    net->num_clients--;
}

disconnect_player_t dc_player(main_net_t *net, client_t *client, char *error)
{
    int id = 0;
    disconnect_player_t error_struct;

    while (&net->clients[id] != client)
        id++;
    error_struct.type = DISCONNECT_PLAYER;
    wstrcpy(error_struct.name, client->players_data->name);
    wstrcpy(error_struct.why, error);
    send_to_client(client, &error_struct);
    sfSocketSelector_removeTcpSocket(net->selector, client->socket);
    sfTcpSocket_disconnect(client->socket);
    less_client(net, id);
    return error_struct;
}

void get_new_client(main_net_t *net)
{
    sfTcpSocket *client_socket = NULL;

    if (sfTcpListener_accept(net->listener, &client_socket) == sfSocketDone) {
        if (net->num_clients >= MAX_CLIENTS) {
            WLOG("Nombre maximal de clients atteint\n", net->log_file);
            sfTcpSocket_destroy(client_socket);
        } else {
            WLOG("new client\n", net->log_file);
            net->clients[net->num_clients].socket = client_socket;
            net->clients[net->num_clients].players_data =
            malloc(sizeof(player_server_t));
            net->num_clients++;
            sfSocketSelector_addTcpSocket(net->selector, client_socket);
        }
    } else
        sfTcpSocket_destroy(client_socket);
}

client_t *get_client_with_username(main_net_t *net, char *username)
{
    for (int i = 0; i < net->num_clients; i++) {
        if (!wstrcmp(net->clients[i].players_data->name, username))
            return &net->clients[i];
    }
    return NULL;
}

list_player_t *get_players_list(main_net_t *net, map_id_t map_id)
{
    list_player_t *ret = malloc(sizeof(list_player_t));
    int index = 0;

    for (int i = 0; i < net->num_clients; i++) {
        if (net->clients[i].players_data->map == map_id) {
            ret->list[index] = *(net->clients[i].players_data);
            index++;
        }
    }
    ret->num_player = index;
    ret->type = PLAYER_LIST;
    return ret;
}
