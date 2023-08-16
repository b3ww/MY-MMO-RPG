/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_update
*/

#include "particle.h"
#include <SFML/Graphics/RectangleShape.h>

static void append_particle(anim_t *anim, particles_t **particles,
particles_t *new_particle)
{
    particles_t *particle = *particles;

    if (*particles == NULL) {
        *particles = new_particle;
        return;
    }
    for (; particle->next != NULL; particle = particle->next);
    particle->next = new_particle;
}

static void add_particles(anim_t *anim, double dt)
{
    anim->spawn_delay -= dt;
    anim->time_elapsed += dt;
    if (anim->duration != -1 && anim->time_elapsed >= anim->duration
    || !anim->is_generating)
        return;
    while (anim->spawn_delay < 0) {
        for (int i = 0; i < anim->batch_size; i++)
            append_particle(anim, &anim->particles, particle_create(anim));
        anim->spawn_delay += anim->spawn_delay_value;
    }
}

void anim_update(anim_t *anim, double dt)
{
    particles_t *particle;
    particles_t *save_next;

    if (anim == NULL)
        return;
    add_particles(anim, dt);
    while (particle_update(anim->particles, dt) == -1) {
        save_next = anim->particles->next;
        particle_destroy(anim->particles);
        anim->particles = save_next;
    }
    particle = anim->particles;
    if (particle != NULL)
        particle = particle->next;
    for (; particle != NULL; particle = particle->next)
        particle_update(particle, dt);
}
