/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_create
*/

#include "particle.h"
#include <stdlib.h>
#include <math.h>

particles_t *particle_create(anim_t *anim)
{
    particles_t *particle = malloc(sizeof(particles_t));

    particle->position = get_random_pos(anim->shape_start);
    set_shape_part(particle, anim);
    set_destination(particle, anim);
    particle->rotation_modifier = anim->rotation_modifier;
    set_rotation(particle->shape_type, particle->shape, anim->rotation);
    particle->color = anim->color;
    particle->scale_props = anim->scale_props;
    particle->move = set_particle_movement(particle->position,
        particle->destination);
    particle->speed = anim->speed;
    particle->time_elapsed = 0;
    particle->arrived = sfFalse;
    particle->anim = anim;
    particle->next = NULL;
    return particle;
}
