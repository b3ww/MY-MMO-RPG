/*
** EPITECH PROJECT, 2023
** lib/particle/set/anim_set_batch_size
** File description:
** set color start and end
*/

#include "particle.h"

void anim_set_batch_size(anim_t *anim, unsigned int batch_size)
{
    anim->batch_size = batch_size;
}
