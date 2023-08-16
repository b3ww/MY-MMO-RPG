/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** move_player_map
*/

#include "rpg_online_manager.h"

void move_player_map(main_net_t *net, int client_id, change_map_t *data)
{
    disconnect_player_t disc;

    strcpy(disc.name, net->clients[client_id].players_data->name);
        disc.type = DISCONNECT_PLAYER;
    strcpy(disc.why, "hi want! demande pas ferero\n");
    send_to_map_w(net, net->clients[client_id].players_data->map,
        &disc, client_id);
    net->clients[client_id].players_data->map = data->dest_map_id;
    net->clients[client_id].players_data->destination = data->dest_map_pos;
    net->clients[client_id].players_data->pos = data->dest_map_pos;
    net->clients[client_id].players_data->type = PLAYER_CONNECTION;
    send_to_client(&net->clients[client_id],
        get_players_list(net, data->dest_map_id));
    send_to_map_w(net, data->dest_map_id,
        net->clients[client_id].players_data, client_id);
    send_to_map(net, data->dest_map_id, &net->clients[client_id].players_data);
}
