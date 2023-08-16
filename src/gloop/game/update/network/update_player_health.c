/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** update_player_health
*/

#include "rpg.h"
#include "attacked.h"
#include "data_type.h"

void update_player_health(net_t *network, player_t *players[50],
uss_t *player_count)
{
    attacked_t *atk = ((attacked_t *)network->rdata);
    uss_t target_id = get_player_id(players, *player_count, atk->name);

    if (target_id > 0 && target_id < *player_count) {
        players[target_id]->stats.health = atk->health;
    }
}
