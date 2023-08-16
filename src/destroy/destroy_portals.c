/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** destroy_portals
*/

#include "portals.h"
#include <stdlib.h>

void destroy_portals(portal_t *portal)
{
    if (portal == NULL)
        return;
    destroy_portals(portal->next);
    sfSprite_destroy(portal->sprite);
    sfClock_destroy(portal->anim_clock);
    free(portal);
}
