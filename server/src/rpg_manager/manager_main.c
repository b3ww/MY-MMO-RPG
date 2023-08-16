/*
** EPITECH PROJECT, 2023
** MMOPRG_ONLINE [SSH]
** File description:
** manager_main
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wnetcsfml.h"
#include "disconnect.h"
#include "data_type.h"
#include "move_share.h"
#include "rpg_online_manager.h"

void send_to_map(main_net_t *net, map_id_t map, void *to_send)
{
    for (int i = 0; i < net->num_clients; i++) {
        if (net->clients[i].players_data->map == map) {
            send_to_client(&net->clients[i], to_send);
        }
    }
}

void send_to_all(main_net_t *net, void *to_send)
{
    for (int i = 0; i < net->num_clients; i++)
        send_to_client(&net->clients[i], to_send);
}

void rpg_online_manager(main_net_t *net, void *manager_v)
{
    client_t *clients = net->clients;
    manager_t *manager = (manager_t *)manager_v;

    for (int i = 0; i < net->num_clients; i++) {
        if (clients[i].to_read)
            read_data(net, &i);
    }
}
