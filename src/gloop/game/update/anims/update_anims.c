/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** update_anims
*/

#include "rpg.h"
#include "rpg_particles.h"

static void enhance_bin_smoke(anim_t *anim)
{
    int color_index = rand() % 11;
    sfColor color;

    switch (color_index) {
    case 0: color = sfColor_fromRGBA(197, 72, 2, 140); break;
    case 1: color = sfColor_fromRGBA(139, 164, 0, 140); break;
    case 2: color = sfColor_fromRGBA(61, 61, 57, 140); break;
    case 3: color = sfColor_fromRGBA(61, 61, 57, 140); break;
    case 4: color = sfColor_fromRGBA(55, 97, 122, 140); break;
    case 5: color = sfColor_fromRGBA(240, 237, 31, 140); break;
    case 6: color = sfColor_fromRGBA(214, 206, 139, 140); break;
    case 7: color = sfColor_fromRGBA(122, 120, 114, 140); break;
    case 8: color = sfColor_fromRGBA(203, 3, 12, 140); break;
    case 9: color = sfColor_fromRGBA(83, 132, 156, 140); break;
    case 10: color = sfColor_fromRGBA(203, 3, 12, 140); break;
    default: break;
    }
    anim_set_color(anim, color);
    anim_set_scale(anim, (v2f_t){0.3 + (float)(rand() % 5) / 10, 0.3 + (float)(rand() % 5) / 10});
}

static void enhance_anim(anim_t *anim)
{
    v2f_t scale;

    switch (anim->id) {
    case RAIN_ANIM:
        anim_set_speed(anim, get_random_nb_between(anim->speed, 500, 2000,
            30));
        scale.x = (float)get_random_nb_between(15, 10, 20, 5) / 100;
        scale.y = (float)get_random_nb_between(200, 50, 400, 10) / 100;
        anim_set_scale(anim, scale);
        break;
    case GO_TO_ANIM:
        if (anim->speed > 1)
            anim_set_speed(anim, anim->speed / 1.2);
        break;
    case BIN_SMOKE_ANIM:
        enhance_bin_smoke(anim);
        break;
    default:
        break;
    }
}

void update_anims(anim_t **anims, double dt)
{
    anim_t *anim = *anims;
    anim_t *next_anim = NULL;

    if (anims == NULL)
        return;
    for (; anim != NULL; anim = next_anim) {
        next_anim = anim->next;
        enhance_anim(anim);
        anim_update(anim, dt);
        anim_destroy_secure(anims, anim);
    }
}
