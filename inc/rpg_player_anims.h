/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** rpg_player_anims
*/

#pragma once

    #include "rpg_particles.h"
    #include "fight.h"

anim_props_t *create_anim_props_spawn(void);
anim_t *create_spawn_anim(anim_props_t *props);
anim_t *adjust_spawn_anim(anim_props_t *anims_props, player_t *player);

anim_t *create_arrow_anim(anim_props_t *props, attack_data_t *attack);
anim_props_t *create_anim_props_arrow(sfTexture *texture);

anim_props_t *create_anim_props_go_to(void);
anim_t *create_go_to_anim(anim_props_t *props);
anim_t *adjust_go_to_anim(anim_props_t *anims_props, v2f_t mpos,
player_t *target);
