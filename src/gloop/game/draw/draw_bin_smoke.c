/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** draw_bin_smoke
*/

#include "rpg_particles.h"

void draw_bin_smoke(sfRenderWindow *window, anim_t *anims)
{
    anim_t *anim = anims;

    for (; anim != NULL; anim = anim->next) {
        if (anim->id == BIN_SMOKE_ANIM)
            anim_draw(window, anim);
    }
}
