/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** update_capy
*/

#include "player.h"

void update_capy(npc_t *capy)
{
    if (GET_CLOCK_SEC(capy->anim_clock) > 0.35) {
        sfClock_restart(capy->anim_clock);
        capy->anim_rect.left += 21;
        if (capy->anim_rect.left > 21)
            capy->anim_rect.left = 0;
        sfSprite_setTextureRect(capy->sprite, capy->anim_rect);
    };
}
