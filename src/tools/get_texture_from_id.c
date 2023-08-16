/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** get_texture_from_id
*/

#include "textures.h"

sfTexture *get_texture_from_id(texture_list_t *textures, uss_t id)
{
    for (; textures != NULL; textures = textures->next) {
        if (textures->id == id)
            return textures->texture;
    }
    return NULL;
}
