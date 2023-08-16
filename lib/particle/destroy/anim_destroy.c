/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_destroy
*/

#include "particle.h"
#include <stdlib.h>

void destroy_scale(scale_t *scale)
{
    if (scale != NULL) {
        free(scale);
    }
}

void anim_destroy(anim_t *anim)
{
    if (anim == NULL)
        return;
    if (anim->previous != NULL)
        anim->previous->next = anim->next;
    if (anim->next != NULL)
        anim->next->previous = anim->previous;
    destroy_particles(anim->particles);
    if (anim->shape_part->is_default)
        destroy_shape(anim->shape_part);
    if (anim->shape_start->is_default)
        destroy_shape(anim->shape_start);
    if (anim->shape_end->is_default)
        destroy_shape(anim->shape_end);
    if (anim->follow_destination) {
        free(anim->shape_start);
        free(anim->shape_end);
    } if (anim->data_to_free)
        free(anim->at_death_data);
    destroy_scale(anim->scale_props);
    free(anim);
}

void anim_destroy_secure(anim_t **anim_list, anim_t *anim)
{
    anim_t *next_anim = NULL;
    bool first_anim = false;

    if (anim == NULL || !is_anim_ended(anim))
        return;
    if (anim->previous == NULL) {
        next_anim = anim->next;
        first_anim = true;
    }
    anim_destroy(anim);
    if (first_anim) {
        anim = next_anim;
        *anim_list = anim;
    }
}
