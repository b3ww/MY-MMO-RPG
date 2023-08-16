/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** create_draw_text
*/

#include "create.h"

sfText *create_draw_text(char *name, sfFont *font)
{
    sfText *draw_text = sfText_create();

    sfText_setFont(draw_text, font);
    sfText_setString(draw_text, name);
    sfText_setCharacterSize(draw_text, 20);
    return draw_text;
}
