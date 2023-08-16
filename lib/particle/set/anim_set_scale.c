/*
** EPITECH PROJECT, 2023
** lib/particle/set/anim_set_scale
** File description:
** set scale
*/

#include "particle.h"

void anim_set_scale(anim_t *anim, sfVector2f scale)
{
    anim->scale = scale;
}
