/*
** EPITECH PROJECT, 2023
** lib/particle/set/anim_set_scale_modifier
** File description:
** set scale modifier
*/

#include "particle.h"
#include <stdlib.h>

void anim_set_scale_modifier(anim_t *anim, v2f_t scale_modifier,
sfVector2f scale_min, sfVector2f scale_max)
{
    if (!anim->scale_props)
        anim->scale_props = malloc(sizeof(scale_t));
    anim->scale_props->scale_min = scale_min;
    anim->scale_props->scale_max = scale_max;
    anim->scale_props->scale_modifier = scale_modifier;
}
