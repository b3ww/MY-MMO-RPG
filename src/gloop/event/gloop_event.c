/*
** EPITECH PROJECT, 2023
** 4_MyMMORPG
** File description:
** gloop_event
*/

#include "rpg.h"

static void set_cursor(cursor_t *cursor, cursor_type_t type)
{
    cursor->type = type;
    sfSprite_setTexture(cursor->sprite, cursor->textures[type], sfFalse);
}

void gloop_event(rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->wd);
    if (event.type == sfEvtMouseButtonPressed)
        set_cursor(rpg->cursor, SELECT_TAP);
    if (event.type == sfEvtMouseButtonReleased)
        set_cursor(rpg->cursor, SELECT);
}
