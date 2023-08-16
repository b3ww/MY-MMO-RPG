/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** map
*/

#pragma once

    #include "portals.h"
    #include "constants.h"
    #include "textures.h"
    #include "map_share.h"

    #define COLLISON(map, x, y) map->hitboxes[y][x] ? true : false
    #define TILE_WIDTH (WIDTH / 20)
    #define TILE_HEIGHT (HEIGHT / 10)

typedef struct entity {
    sfSprite *sprite;
    bool upper;
    v2f_t position;
} entity_t;

typedef struct map {
    v2f_t size;
    sfTexture *background;
    sfSprite *background_sprite;
    portal_t *portals;
    entity_t **entities;
    bool **hitboxes;
    bool fight;
    map_id_t id;
} map_t;

bool stack_hitbox(map_t *to_stack, char **to_parse, v2f_t size);
void stack_portals(map_t *to_stack, char **to_parse,
    texture_list_t *textures);
void set_portal_pos(portal_t *portal, char to_parse, int i, int j);
int get_texture_id(char code);
