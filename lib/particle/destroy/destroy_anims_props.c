/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** destroy_anims_props
*/

#include "particle.h"
#include <stdlib.h>

void destroy_anims_props(anim_props_t *anims_props)
{
    anim_props_t *save;

    for (; anims_props != NULL; anims_props = save) {
        save = anims_props->next;
        destroy_shape(anims_props->shape_part);
        destroy_shape(anims_props->shape_start);
        if (anims_props->follow_dest)
            free(anims_props->shape_end);
        else
            destroy_shape(anims_props->shape_end);
        free(anims_props);
    }
}
