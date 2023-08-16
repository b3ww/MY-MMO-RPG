/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** center_sprite
*/

#include "shortcut.h"

void center_sprite(sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    sfSprite_move(sprite, (v2f_t){-bounds.width / 2, -bounds.height / 2});
}
