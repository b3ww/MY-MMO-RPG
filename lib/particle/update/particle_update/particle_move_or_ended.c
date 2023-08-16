/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** particle_move_or_ended
*/

#include "particle.h"
#include <math.h>

static int is_particle_arrived(particles_t *part, v2f_t pos)
{
    if (sqrt(pow(part->position.x - part->destination.x, 2) +
    pow(part->position.y - part->destination.y, 2)) <= sqrt(pow(pos.y -
    part->destination.y, 2) + pow(pos.x - part->destination.x, 2)))
        return 1;
    return 0;
}

int particles_move_or_ended(particles_t *part, double dt)
{
    v2f_t pos;

    if (part == NULL)
        return 0;
    pos.x = part->position.x + part->move.x * part->speed * dt;
    pos.y = part->position.y + part->move.y * part->speed * dt;
    if (is_particle_arrived(part, pos)) {
        if (part->anim->at_death != NULL)
            part->anim->at_death(part->anim->at_death_data);
        part->arrived = sfTrue;
        return 1;
    }
    part->position = pos;
    return 0;
}
