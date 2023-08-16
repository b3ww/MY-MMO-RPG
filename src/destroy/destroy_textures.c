/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** destroy_textures
*/

#include "destroy.h"
#include "textures.h"

void destroy_textures(texture_list_t *textures)
{
    if (textures == NULL)
        return;
    destroy_textures(textures->next);
    sfTexture_destroy(textures->texture);
    free(textures);
}
