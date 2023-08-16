/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_shape
*/

#include "particle.h"

void anim_set_shape_part(anim_t *anim, shape_t *shape_part)
{
    if (shape_part == NULL)
        return;
    if (anim->shape_part->is_default)
        destroy_shape(anim->shape_part);
    anim->shape_part = shape_part;
}
