/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** update_hud
*/

#include "hud.h"
#include "player.h"

void update_hud(hud_t *hud, player_t *player)
{
    hud->health_bar_rect.width = (player->stats.health + 1) *
        hud->max_health_bar_width / player->stats.max_health;
    sfSprite_setTextureRect(hud->health_bar, hud->health_bar_rect);
}
