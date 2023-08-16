/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** animate_player
*/

#include "player.h"
#include "v2f_operations.h"

static float get_anim_speed(player_t *player)
{
    if (player->skin.anim_state == ATTACK_STATE)
        return 1 / player->fight.attack_speed / 4;
    if (player->skin.anim_state == MOVEMENT_STATE)
        return 1 / ((float)player->move.speed / 30);
    return IDLE_ANIM_SPEED;
}

void animate_player(player_t *player)
{
    sfIntRect anim_rect = player->skin.anim_rect;
    float anim_speed = get_anim_speed(player);

    if (GET_CLOCK_SEC(player->skin.anim_clock) > anim_speed) {
        player->skin.anim_rect.left += 32;
        sfClock_restart(player->skin.anim_clock);
        if (player->skin.anim_rect.left > 32 * 3)
            player->skin.anim_rect.left = player->skin.anim_state ==
                DEATH_STATE ? 32 : 0;
    }
    if (player->skin.anim_state != IDLE_STATE) {
        anim_rect.top += 32 * player->skin.anim_state;
    }
    sfSprite_setTextureRect(player->skin.sprite, anim_rect);
}
