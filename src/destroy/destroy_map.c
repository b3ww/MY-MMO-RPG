/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** destroy_map
*/

#include "map.h"
#include "wcsv.h"
#include "destroy.h"
#include "tools.h"

static void destroy_entity(entity_t *entity)
{
    sfSprite_destroy(entity->sprite);
    free(entity);
}

void destroy_map(map_t *map)
{
    if (map == NULL)
        return;
    sfTexture_destroy(map->background);
    sfSprite_destroy(map->background_sprite);
    destroy_portals(map->portals);
    TABFREE(map->hitboxes);
    for (int i = 0; map->entities[i]; i++)
        destroy_entity(map->entities[i]);
    free(map);
}
