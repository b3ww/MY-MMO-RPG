/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** load_map
*/

#include "map.h"
#include "wcsv.h"
#include "tools.h"
#include "struct.h"
#include "create.h"
#include "constants.h"
#include <stdio.h>

int get_texture_id(char code)
{
    switch (code) {
        case 't': return 0;
        case 'T': return 1;
        case 'v': return 2;
        case 'M': return 3;
        case 'm': return 4;
        case 'q': return 5;
        case 'l': return 6;
        case 'B': return 7;
        default: return 0;
    }
}

static void load_background(map_t *map)
{
    v2f_t resize;

    map->background_sprite = sfSprite_create();
    sfSprite_setTexture(map->background_sprite, map->background, sfFalse);
    resize.x = WIDTH / sfSprite_getLocalBounds(map->background_sprite).width;
    resize.y = HEIGHT / sfSprite_getLocalBounds(map->background_sprite).height;
    sfSprite_scale(map->background_sprite, resize);
}

map_t *load_map(rpg_t *rpg, map_id_t id)
{
    map_t *ret = malloc(sizeof(map_t));
    char **map_data = rpg->file_config.maps->content[id + 1];
    char *tmp = open_file(map_data[2]);
    char **to_parse = wstr_to_word_array(tmp, "\n");

    ret->id = id;
    ret->size = (v2f_t){my_getnbr(to_parse[0]), my_getnbr(to_parse[1])};
    stack_portals(ret, to_parse + 2, rpg->textures);
    if (!stack_hitbox(ret, to_parse + 6, ret->size)) {
        TABFREE(to_parse);
        return NULL;
    }
    stack_entities(ret, to_parse + 16, ret->size, rpg);
    ret->background = sfTexture_createFromFile(map_data[1], 0);
    load_background(ret);
    TABFREE(to_parse);
    return ret;
}

void set_portal_pos(portal_t *portal, char to_parse, int i, int j)
{
    portal_e_t id = to_parse - 'a';

    while (portal && id != portal->id)
        portal = portal->next;
    if (!portal)
        return;
    sfSprite_setPosition(portal->sprite, (v2f_t){(j * TILE_WIDTH) -
        (TILE_WIDTH / 2), (i * TILE_HEIGHT) - (TILE_HEIGHT)});
}
