/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_particle_destination
*/

#include "particle.h"

void set_destination(particles_t *part, anim_t *anim)
{
    switch (anim->shape_end->type) {
    case MIRROR:
        part->destination = (v2f_t){
            part->position.x + anim->shape_end->body.offset.x,
            part->position.y + anim->shape_end->body.offset.y};
        break;
    case SPRITE:
    case SPRITE_CENTER:
        part->destination = get_sprite_center(anim->shape_end->body.sprite);
        break;
    default:
        part->destination = get_random_pos(anim->shape_end);
        break;
    }
}
