/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** apply_player_connection
*/

#include "rpg.h"
#include "create.h"
#include "string.h"
#include <stdlib.h>
#include "player.h"

int apply_player_connection(net_t *network, player_t *players[50],
uss_t *player_count, sfFont *font)
{
    player_server_t *player_server = ((player_server_t *)network->rdata);
    int player_found;
    int player_id;

    player_found = get_player_id(players, *player_count, player_server->name);
    player_id = player_found;
    if (player_id == -1) {
        players[*player_count] = malloc(sizeof(player_t));
        player_id = *player_count;
        (*player_count)++;
    }
    players[player_id] = set_player_client(players[player_id],
        player_server, player_found + 1, font);
    return player_id;
}
