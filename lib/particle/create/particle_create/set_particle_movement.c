/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_particle_movement
*/

#include "particle.h"

v2f_t set_particle_movement(v2f_t spawn_pos, v2f_t dest)
{
    v2f_t direction = {dest.x - spawn_pos.x, dest.y - spawn_pos.y};

    float dir_norm = vector_norm(direction);
    return float_multiply_v2f(direction, 1 / dir_norm);
}
