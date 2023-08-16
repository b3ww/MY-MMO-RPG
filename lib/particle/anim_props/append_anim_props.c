/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** append_anim_props
*/

#include "particle.h"

void append_anim_props(anim_props_t **anim_props, anim_props_t *to_add)
{
    anim_props_t *browse = *anim_props;

    if (*anim_props == NULL) {
        *anim_props = to_add;
        return;
    }
    for (; browse->next != NULL; browse = browse->next);
    browse->next = to_add;
}
