/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** draw_hud
*/

#include "hud.h"

void draw_hud(sfRenderWindow *wd, hud_t *hud)
{
    sfRenderWindow_drawSprite(wd, hud->background, NULL);
    sfRenderWindow_drawSprite(wd, hud->health_bar, NULL);
}
