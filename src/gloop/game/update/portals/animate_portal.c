/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** animate_portal
*/

#include "portals.h"

void animate_portal(portal_t *portal)
{
    int width;

    if (portal == NULL)
        return;
    width = portal->anim_rect.width;
    if (GET_CLOCK_SEC(portal->anim_clock) > 0.1) {
        portal->anim_rect.left += width;
        sfClock_restart(portal->anim_clock);
        if (portal->anim_rect.left > width * 7) {
            portal->anim_state = portal->anim_state == P_IDLE ?
                portal->anim_state : P_IDLE;
            portal->anim_rect.left = 0;
        }
    }
    portal->anim_rect.top = width * portal->anim_state;
    sfSprite_setTextureRect(portal->sprite, portal->anim_rect);
}
