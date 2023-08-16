/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** mouse_on_player
*/

#include "player.h"

int mouse_on_player(player_t *me, player_t *player, v2i_t mpos)
{
    sfFloatRect hitbox;

    hitbox = sfRectangleShape_getGlobalBounds(player->skin.hitbox);
    player->skin.show_hitbox = false;
    if (sfFloatRect_contains(&hitbox, mpos.x, mpos.y) &&
    player->skin.color != me->skin.color) {
        player->skin.show_hitbox = true;
        return player->id;
    }
    return -1;
}
