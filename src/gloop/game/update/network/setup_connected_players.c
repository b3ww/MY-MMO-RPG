/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** setup_connected_player
*/

#include "rpg.h"
#include "create.h"
#include "string.h"
#include <stdlib.h>
#include "player.h"

static void setup_player(player_t *players[50], uss_t *player_count,
sfFont *font, player_server_t new_player)
{
    int player_found;
    int player_id;

    player_found = get_player_id(players, *player_count, new_player.name);
    player_id = player_found;
    if (player_id == -1) {
        players[*player_count] = malloc(sizeof(player_t));
        player_id = *player_count;
        (*player_count)++;
    }
    players[player_id] = set_player_client(players[player_id], &new_player,
        player_found + 1, font);
}

void setup_connected_players(net_t *network, player_t *players[50],
uss_t *player_count, sfFont *font)
{
    list_player_t *player_list = ((list_player_t *)network->rdata);

    for (int i = 0; i < player_list->num_player; i++) {
        setup_player(players, player_count, font, player_list->list[i]);
    }
}
