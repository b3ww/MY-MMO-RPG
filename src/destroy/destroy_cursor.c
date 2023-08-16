/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** destroy_cursor
*/

#include "struct.h"
#include "destroy.h"

void destroy_cursor(cursor_t *cursor)
{
    sfSprite_destroy(cursor->sprite);
    for (int i = 0; i < 3; i++)
        sfTexture_destroy(cursor->textures[i]);
    free(cursor);
}
