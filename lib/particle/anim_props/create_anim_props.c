/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** create_anim_props
*/

#include "particle.h"
#include <stdlib.h>

anim_props_t *create_anim_props(int type, shape_t *shape_part,
shape_t *shape_start, shape_t *shape_end)
{
    anim_props_t *anim_props = malloc(sizeof(anim_props_t));

    anim_props->type = type;
    anim_props->shape_part = shape_part;
    anim_props->shape_start = shape_start;
    anim_props->shape_end = shape_end;
    anim_props->follow_dest = false;
    anim_props->part_texture = NULL;
    anim_props->next = NULL;
    return anim_props;
}
