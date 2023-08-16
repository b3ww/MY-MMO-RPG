/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** spawn_player
*/

#include "player.h"
#include "create.h"
#include "tools.h"

void spawn_player(player_t *player, texture_list_t *textures)
{
    player->skin.show_player = false;
    append_portal(&player->portal, create_portal(
        get_texture_from_id(textures, GREEN_PORTAL_ID)));
    sfSprite_setPosition(player->portal->sprite, player->move.pos);
    center_sprite(player->portal->sprite);
    player->portal->anim_state = P_SPAWN;
}
