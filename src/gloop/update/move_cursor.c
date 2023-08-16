/*
** EPITECH PROJECT, 2023
** 4_MyMMORPG
** File description:
** move_cursor
*/

#include "rpg.h"

void move_cursor(cursor_t *cursor, v2i_t mpos)
{
    sfVector2f pos;

    pos.x = mpos.x - cursor->hotspots[cursor->type].x;
    pos.y = mpos.y - cursor->hotspots[cursor->type].y;
    sfSprite_setPosition(cursor->sprite, pos);
}
