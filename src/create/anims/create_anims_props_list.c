/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** create_anim_props
*/

#include "rpg_player_anims.h"
#include <stdlib.h>
#include "textures.h"
#include "tools.h"

anim_props_t *create_anims_props_list(texture_list_t *textures)
{
    anim_props_t *anim_props = NULL;

    append_anim_props(&anim_props, create_anim_props_rain());
    append_anim_props(&anim_props, create_anim_props_spawn());
    append_anim_props(&anim_props, create_anim_props_arrow(get_texture_from_id(
        textures, ARROW_TEXTURE_ID
    )));
    append_anim_props(&anim_props, create_anim_props_go_to());
    append_anim_props(&anim_props, create_anim_props_smoke());
    append_anim_props(&anim_props, create_anim_props_splash_smoke());
    return anim_props;
}
