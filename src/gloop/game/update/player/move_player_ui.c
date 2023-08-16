/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** move_player_ui
*/
#include "player.h"

void move_text(v2f_t player_pos, sfText *text, v2f_t offset)
{
    sfFloatRect text_rect = sfText_getGlobalBounds(text);

    player_pos.x -= text_rect.width / 2 - offset.x;
    player_pos.y -= text_rect.height / 2 - offset.y;
    sfText_setPosition(text, player_pos);
}

void move_health_bar(player_t *player)
{
    v2f_t hb_pos = player->move.pos;
    sfFloatRect hb_rect = sfRectangleShape_getGlobalBounds(
        player->stats.health_bar);
    float hb_size = player->stats.health * HB_MAX_WIDTH /
        player->stats.max_health;

    sfRectangleShape_setSize(player->stats.health_bar,
        (v2f_t){hb_size, HB_MAX_HEIGHT});
    hb_rect = sfRectangleShape_getGlobalBounds(player->stats.health_bar);
    hb_pos.x -= hb_rect.width / 2;
    hb_pos.y -= hb_rect.height / 2 + 40;
    sfRectangleShape_setPosition(player->stats.health_bar, hb_pos);
}

void move_player_ui(player_t *player)
{
    move_text(player->move.pos, player->stats.draw_name, (v2f_t){0, -70});
    move_text(player->move.pos, player->fight.draw_kills, (v2f_t){0, -85});
    move_health_bar(player);
}
