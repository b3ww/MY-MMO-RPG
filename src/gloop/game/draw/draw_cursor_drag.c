/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** draw_cursor_drag
*/

#include "cursor.h"

void draw_cursor_drag(sfRenderWindow *wd, cursor_t *cursor)
{
    if (cursor->drag) {
        (cursor->drag->type == CONSO) ? sfRenderWindow_drawSprite(wd,
            cursor->drag->slots->conso->sprite, NULL) :
            sfRenderWindow_drawSprite(wd,
            cursor->drag->slots->unconso->sprite, NULL);
    }
}
