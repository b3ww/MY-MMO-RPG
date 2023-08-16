/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** load_textures
*/

#include "textures.h"
#include <stdlib.h>

static void append_texture(texture_list_t *list, char *texture_path,
uss_t id)
{
    if (list == NULL)
        return;
    for (; list->next != NULL; list = list->next);
    list->next = malloc(sizeof(texture_list_t));
    list->next->id = id;
    list->next->texture = sfTexture_createFromFile(texture_path, NULL);
    list->next->next = NULL;
}

static void load_entities_textures(texture_list_t *textures)
{
    append_texture(textures, "assets/maps/red/assets/red_tree.png",
        E_RTREE);
    append_texture(textures, "assets/maps/blue/assets/blue_tree.png",
        E_BTREE);
    append_texture(textures, "assets/maps/green/assets/green_tree.png",
        E_GTREE);
    append_texture(textures, "assets/maps/red/assets/red_house.png",
        E_RHOUSE);
    append_texture(textures, "assets/maps/blue/assets/blue_house.png",
        E_BHOUSE);
    append_texture(textures, "assets/maps/green/assets/green_house.png",
        E_GHOUSE);
    append_texture(textures, "assets/maps/base/assets/h_bridge.png",
        E_HBRIDGE);
    append_texture(textures, "assets/maps/base/assets/v_bridge.png",
        E_VBRIDGE);
}

texture_list_t *load_textures(void)
{
    texture_list_t *textures = malloc(sizeof(texture_list_t));

    textures->id = ARROW_TEXTURE_ID;
    textures->next = NULL;
    textures->texture = sfTexture_createFromFile(ARROW_PATH, NULL);

    append_texture(textures, GREEN_PORTAL_PATH, GREEN_PORTAL_ID);
    append_texture(textures, PURPLE_PORTAL_PATH, PURPLE_PORTAL_ID);
    load_entities_textures(textures);

    return textures;
}
