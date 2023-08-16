/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** create_fade_to_black
*/

#include "create.h"
#include "constants.h"

fade_to_black_t *create_fade_to_black(void)
{
    fade_to_black_t *fade_to_black = malloc(sizeof(fade_to_black_t));
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (v2f_t){WIDTH, HEIGHT});
    sfRectangleShape_setFillColor(rect, sfBlack);

    fade_to_black->active = false;
    fade_to_black->alpha = 0;
    fade_to_black->rect = rect;
    fade_to_black->portal = NULL;
    return fade_to_black;
}
