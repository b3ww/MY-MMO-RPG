/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** adjust_spawn_anim
*/

#include "rpg_player_anims.h"
#include "v2f_operations.h"
#include "tools.h"

anim_t *adjust_spawn_anim(anim_props_t *anims_props, player_t *player)
{
    anim_t *anim = create_spawn_anim(get_anims_props(anims_props, SPAWN_ANIM));
    sfColor color = get_color(player->skin.color);
    sfColor spawn_color = sfColor_fromRGBA(color.r, color.g, color.b, 140);

    anim_set_color(anim, spawn_color);
    sfCircleShape_setPosition(anim->shape_start->body.circle,
        player->move.pos);
    sfCircleShape_setPosition(anim->shape_end->body.circle,
        float_add_v2f(player->move.pos, -sfCircleShape_getRadius(
        anim->shape_end->body.circle)));
    return anim;
}
