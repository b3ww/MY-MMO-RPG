/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_append
*/

#include "particle.h"

void anim_append(anim_t **anim_list, anim_t *new_anim)
{
    anim_t *anim = *anim_list;

    if (anim == NULL) {
        *anim_list = new_anim;
        return;
    }
    for (; anim->next != NULL; anim = anim->next);
    new_anim->previous = anim;
    anim->next = new_anim;
}
