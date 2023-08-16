/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** set_skin
*/

#include "rpg.h"
#include "colors.h"

static sfRectangleShape *create_hitbox(player_t *player)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfFloatRect bnd = sfSprite_getGlobalBounds(player->skin.sprite);

    sfRectangleShape_setSize(rect, (v2f_t){bnd.width, bnd.height});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 3);
    sfRectangleShape_setOutlineColor(rect, LIGHT_RED);
    return rect;
}

void set_skin(player_t *player, player_server_t *player_server,
int player_found)
{
    player->skin.pclass = player_server->player_class;
    player->skin.color = player_server->color;
    if (!player_found) {
        player->skin.sprite = sfSprite_create();
        player->skin.texture = NULL;
        player->skin.anim_clock = sfClock_create();
        player->skin.hitbox = create_hitbox(player);
        player->skin.show_hitbox = false;
    }
    player->skin.scale = (v2f_t){4, 4};
    player->skin.anim_rect = (sfIntRect){0, 0, 32, 32};
    player->skin.anim_state = player_server->anim_state;
    player->skin.show_player = true;
    reload_player_skin(player);
}
