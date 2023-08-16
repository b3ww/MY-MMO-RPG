/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** set_player_direction
*/

#include "rpg.h"
#include "math.h"

static direction_t get_direction(sfVector2f velocity)
{
    float angle = atan2f(velocity.y, velocity.x);

    if (angle > -PI_4 && angle < PI_4) {
        return RIGHT;
    }
    if (angle >= PI_4 && angle < 3 * PI_4) {
        return DOWN;
    }
    if (angle >= 3 * PI_4 || angle < -3 * PI_4) {
        return LEFT;
    }
    if (angle >= -3 * PI_4 && angle < -PI_4) {
        return UP;
    }
    return RIGHT;
}

void set_player_direction(player_t *player)
{
    player->move.direction = get_direction(player->move.velocity);
    switch (player->move.direction) {
    case UP: player->skin.anim_rect.top = 10 * 32; break;
    case DOWN: player->skin.anim_rect.top = 5 * 32; break;
    case RIGHT:
        player->skin.anim_rect.top = 0;
        sfSprite_setScale(player->skin.sprite, player->skin.scale);
        break;
    case LEFT:
        player->skin.anim_rect.top = 0;
        sfSprite_setScale(player->skin.sprite, (v2f_t){-player->skin.scale.x,
            player->skin.scale.y});
        break;
    default: break;
    }
}
