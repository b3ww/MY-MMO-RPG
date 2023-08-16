/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** destroy_hud
*/

#include "destroy.h"

void destroy_hud(hud_t *hud)
{
    sfSprite_destroy(hud->background);
    sfTexture_destroy(hud->background_texture);
    sfSprite_destroy(hud->health_bar);
    sfTexture_destroy(hud->health_bar_texture);
    free(hud);
}
