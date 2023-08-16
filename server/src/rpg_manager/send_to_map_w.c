/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** send_to_map_w
*/

#include "wnetcsfml.h"

void send_to_map_w(main_net_t *net, map_id_t map, void *to_send, int cli)
{
    for (int i = 0; i < net->num_clients; i++) {
        if (net->clients[i].players_data->map == map &&
        i != cli)
            send_to_client(&net->clients[i], to_send);
    }
}
