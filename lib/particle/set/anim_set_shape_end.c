/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_shape_ends
*/

#include "particle.h"

void anim_set_shape_end(anim_t *anim, shape_t *shape_end)
{
    if (shape_end == NULL)
        return;
    if (anim->shape_end->is_default) {
        destroy_shape(anim->shape_end);
    }
    anim->shape_end = shape_end;
}
