/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** move_player
*/

#include "rpg.h"
#include "v2f_operations.h"
#include <math.h>
#include "rpg_particles.h"

static bool is_player_arrived(v2f_t pos, v2f_t p_dest, v2f_t p_pos)
{
    if (sqrt(pow(p_pos.x - p_dest.x, 2) + pow(p_pos.y - p_dest.y, 2)) <=
    sqrt(pow(pos.y - p_dest.y, 2) + pow(pos.x - p_dest.x, 2)))
        return true;
    return false;
}

static v2i_t get_player_tile(v2f_t pos)
{
    v2i_t tile;

    tile.x = (int)(pos.x / TILE_WIDTH);
    tile.y = (int)(pos.y / TILE_HEIGHT);
    return tile;
}

void move_player(player_t *player, double dt, bool **hitboxes)
{
    v2f_t move = float_multiply_v2f(player->move.velocity, dt *
        player->move.speed);
    v2i_t tile;
    v2f_t pos;

    pos.x = player->move.pos.x + move.x;
    pos.y = player->move.pos.y + move.y;
    tile = get_player_tile(pos);

    if (is_player_arrived(pos, player->move.destination, player->move.pos) ||
    (((tile.y >= 0 && tile.y < 10) && (tile.x >= 0 && tile.x < 20)) &&
    hitboxes[tile.y][tile.x])) {
        player->move.destination = player->move.pos;
        if (player->skin.anim_state == MOVEMENT_STATE)
            player->skin.anim_state = IDLE_STATE;
        return;
    }
    player->move.pos = pos;
    sfRectangleShape_setPosition(player->skin.hitbox, player->move.pos);
}
