/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** draw_particles
*/

#include "struct.h"
#include "particle.h"

void draw_particles(sfRenderWindow *window, anim_t *anims)
{
    anim_t *anim = anims;

    for (; anim != NULL; anim = anim->next)
        anim_draw(window, anim);
}
