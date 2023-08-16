/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** apply_player_update
*/

#include "rpg.h"
#include "create.h"
#include <stdlib.h>
#include "player.h"
#include "tools.h"

void apply_player_update(net_t *network, player_t *players[50], uss_t *pcount)
{
    player_server_t *player_server = ((player_server_t *)network->rdata);
    int player_id;

    player_id = get_player_id(players, *pcount, player_server->name);
    if (player_id == -1)
        return;

    set_player_client(players[player_id], player_server, 1, NULL);
}
