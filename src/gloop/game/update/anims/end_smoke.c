/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** end_smoke
*/

#include "rpg_particles.h"

void end_smoke(anim_t *anim)
{
    for (; anim != NULL; anim = anim->next) {
        if (anim->id == BIN_SMOKE_ANIM)
            anim->duration = 0;
    }
}
