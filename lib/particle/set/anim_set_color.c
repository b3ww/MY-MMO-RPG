/*
** EPITECH PROJECT, 2023
** lib/particle/set/anim_set_color
** File description:
** set color start and end
*/

#include "particle.h"

void anim_set_color(anim_t *anim, sfColor color)
{
    anim->color = color;
}
