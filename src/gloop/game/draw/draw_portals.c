/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** draw_portals
*/

#include "portals.h"

void draw_portals(sfRenderWindow *wd, portal_t *portals)
{
    for (; portals != NULL; portals = portals->next)
        sfRenderWindow_drawSprite(wd, portals->sprite, NULL);
}
