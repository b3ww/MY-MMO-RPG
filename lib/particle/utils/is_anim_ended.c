/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** is_anim_ended
*/

#include "particle.h"

int is_anim_ended(anim_t *anim)
{
    if (anim == NULL)
        return 0;
    if (anim->particles == NULL && anim->time_elapsed > anim->duration &&
    anim->duration != -1)
        return 1;
    return 0;
}
