/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** hud
*/

#pragma once

    #include "player.h"

    #define BACKGROUND_HUD_PATH "assets/combat/hud/spells.png"
    #define HEALTH_BAR_HUD_PATH "assets/combat/hud/health_bar.png"
    #define UPGRADE_SPELL "assets/combat/hud/upgrade_spell.png"

typedef struct hud {
    sfSprite *background;
    sfTexture *background_texture;
    sfSprite *health_bar;
    sfTexture *health_bar_texture;
    sfIntRect health_bar_rect;
    int max_health_bar_width;
} hud_t;

void update_hud(hud_t *hud, player_t *player);
