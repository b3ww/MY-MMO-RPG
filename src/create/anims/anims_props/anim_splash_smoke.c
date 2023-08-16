/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** first_anims
*/

#include "rpg_particles.h"
#include <stdlib.h>

static shape_t *start(void)
{
    shape_t *smoke_shape_start = malloc(sizeof(shape_t));
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f_t){1000, 650});
    sfRectangleShape_setSize(rect, (v2f_t){70, 100});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(170, 250, 210, 0));
    smoke_shape_start->type = RECT;
    smoke_shape_start->body.rect = rect;
    smoke_shape_start->is_default = false;
    return smoke_shape_start;
}

static shape_t *end(void)
{
    shape_t *smoke_shape_end = malloc(sizeof(shape_t));
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f_t){1050, -100});
    sfRectangleShape_setSize(rect, (v2f_t){310, 500});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(230, 200, 180, 0));
    smoke_shape_end->type = RECT;
    smoke_shape_end->body.rect = rect;
    smoke_shape_end->is_default = false;
    return smoke_shape_end;
}

anim_props_t *create_anim_props_splash_smoke(void)
{
    anim_props_t *anim = create_anim_props(SMOKE_ANIM, NULL,
        start(), end());
    return anim;
}

anim_t *create_splash_smoke(anim_props_t *props)
{
    anim_t *anim = anim_create();

    set_anim_props(anim, props);
    anim_set_frequency(anim, 200);
    anim_set_batch_size(anim, 2);
    anim_set_duration(anim, -1);
    anim_set_speed(anim, 130);
    anim_set_scale(anim, (v2f_t){0.4, 0.4});
    anim_set_color(anim, sfColor_fromRGBA(60, 70, 80, 140));
    return anim;
}
