/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** destroy_fade_to_black
*/

#include "destroy.h"
#include "screen_effect.h"

void destroy_fade_to_black(fade_to_black_t *fade_to_black)
{
    sfRectangleShape_destroy(fade_to_black->rect);
    free(fade_to_black);
}
