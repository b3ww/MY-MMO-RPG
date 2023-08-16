/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** adjust_go_to_anim
*/

#include "rpg_player_anims.h"
#include "v2f_operations.h"
#include "tools.h"
#include "colors.h"

anim_t *adjust_go_to_anim(anim_props_t *anims_props, v2f_t mpos,
player_t *target)
{
    anim_t *anim = create_go_to_anim(get_anims_props(anims_props, GO_TO_ANIM));

    sfCircleShape_setPosition(anim->shape_end->body.circle, mpos);
    sfCircleShape_setPosition(anim->shape_start->body.circle,
        float_add_v2f(mpos, -sfCircleShape_getRadius(
        anim->shape_start->body.circle)));
    if (target != NULL)
        anim_set_color(anim, LIGHT_RED);
    return anim;
}
