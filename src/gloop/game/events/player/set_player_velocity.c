/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** set_player_velocity
*/

#include "rpg.h"
#include "v2f_operations.h"

void set_player_velocity(player_t *player, v2i_t mpos)
{
    v2f_t dir = {mpos.x - player->move.pos.x, mpos.y - player->move.pos.y};

    player->move.destination.x = mpos.x;
    player->move.destination.y = mpos.y;
    player->move.velocity = float_multiply_v2f(dir, 1 / vector_norm(dir) *
        player->move.speed);
}
