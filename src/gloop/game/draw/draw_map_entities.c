/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** draw_map_entities
*/

#include "map.h"

void draw_map_entities(sfRenderWindow *wd, map_t *map, bool draw)
{
    if (map == NULL)
        return;
    for (int i = 0; map->entities[i]; i++) {
        if (map->entities[i]->upper == draw)
            sfRenderWindow_drawSprite(wd, map->entities[i]->sprite, NULL);
    }
}
