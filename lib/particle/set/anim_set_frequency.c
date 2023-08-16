/*
** EPITECH PROJECT, 2023
** lib/particle/set/anim_set_frequency
** File description:
** set frequency of the apparition of particules
*/

#include "particle.h"

void anim_set_frequency(anim_t *anim, float frequency)
{
    if (frequency < 0)
        frequency = -frequency;
    if (frequency == 0)
        anim->spawn_delay_value = 1000000000.0;
    else {
        anim->spawn_delay_value = 1 / frequency;
        anim->spawn_delay = 0;
    }
}
