/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** create_hud
*/

#include "create.h"

static void set_health_bar(hud_t *hud, v2f_t hud_pos)
{
    hud->health_bar_texture = sfTexture_createFromFile(HEALTH_BAR_HUD_PATH,
        NULL);
    hud->health_bar = sfSprite_create();
    sfSprite_setPosition(hud->health_bar, hud_pos);
    sfSprite_move(hud->health_bar, (v2f_t){69, 118});
    sfSprite_setColor(hud->health_bar, sfColor_fromRGBA(255, 255, 255, 100));
    hud->health_bar_rect = sfSprite_getTextureRect(hud->health_bar);
    hud->max_health_bar_width = hud->health_bar_rect.width;
}

hud_t *create_hud(void)
{
    hud_t *hud = malloc(sizeof(hud_t));
    v2f_t hud_pos = {700, 900};

    hud->background_texture = sfTexture_createFromFile(BACKGROUND_HUD_PATH,
        NULL);
    hud->background = sfSprite_create();
    sfSprite_setPosition(hud->background, hud_pos);
    sfSprite_setColor(hud->background, sfColor_fromRGBA(255, 255, 255, 220));
    set_health_bar(hud, hud_pos);
    return hud;
}
