/*
** EPITECH PROJECT, 2023
** lib/particle/set/anim_set_is_generating
** File description:
** Set the speednes of the annimation
*/

#include "particle.h"

void anim_set_is_generating(anim_t *anim, bool is_generating)
{
    anim->is_generating = is_generating;
}
