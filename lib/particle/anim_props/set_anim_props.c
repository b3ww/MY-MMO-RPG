/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_anim_props
*/

#include "particle.h"

void set_anim_props(anim_t *anim, anim_props_t *props)
{
    anim_set_id(anim, props->type);
    anim_set_shape_part(anim, props->shape_part);
    anim_set_shape_start(anim, props->shape_start);
    anim_set_shape_end(anim, props->shape_end);
    anim->follow_destination = props->follow_dest;
}
