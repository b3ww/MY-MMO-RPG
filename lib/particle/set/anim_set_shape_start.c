/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_shape_start
*/

#include "particle.h"

void anim_set_shape_start(anim_t *anim, shape_t *shape_start)
{
    if (shape_start == NULL)
        return;
    if (anim->shape_start->is_default)
        destroy_shape(anim->shape_start);
    anim->shape_start = shape_start;
}
