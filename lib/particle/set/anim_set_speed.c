/*
** EPITECH PROJECT, 2023
** lib/particle/set/anim_set_speed
** File description:
** Set the speednes of the annimation
*/

#include "particle.h"

void anim_set_speed(anim_t *anim, int speed)
{
    anim->speed = speed;
}
