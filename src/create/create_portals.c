/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** create_portals
*/

#include "portals.h"
#include <stdlib.h>

void append_portal(portal_t **portal_list, portal_t *to_append)
{
    portal_t *portal = *portal_list;

    if (*portal_list == NULL) {
        *portal_list = to_append;
        return;
    }
    for (; portal->next != NULL; portal = portal->next);
    portal->next = to_append;
}

portal_t *create_portal(sfTexture *texture)
{
    portal_t *portal = malloc(sizeof(portal_t));

    portal->sprite = sfSprite_create();
    sfSprite_setTexture(portal->sprite, texture, false);
    portal->anim_clock = sfClock_create();
    portal->anim_state = P_IDLE;
    portal->anim_rect = (sfIntRect){0, 0, 64, 64};
    portal->id = 0;
    sfSprite_setTextureRect(portal->sprite, portal->anim_rect);
    sfSprite_setScale(portal->sprite, (v2f_t){3, 3});
    sfSprite_setPosition(portal->sprite, (v2f_t){600, 400});
    portal->next = NULL;
    return portal;
}
