/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** destroy_anims
*/

#include "particle.h"

void destroy_anims(anim_t *anim)
{
    if (anim == NULL)
        return;
    destroy_anims(anim->next);
    anim_destroy(anim);
}
