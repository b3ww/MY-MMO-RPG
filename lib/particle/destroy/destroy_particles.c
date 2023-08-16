/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** destroy_particles
*/

#include "particle.h"
#include <stdlib.h>

void destroy_particles(particles_t *particle)
{
    if (particle == NULL)
        return;
    destroy_particles(particle->next);
    destroy_shape_part(particle->shape_type, particle->shape);
    free(particle);
}
