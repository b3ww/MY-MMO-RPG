/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_rain
*/

#include "rpg_particles.h"
#include <stdlib.h>

static shape_t *start(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (v2f_t){0, -50});
    sfRectangleShape_setSize(rect, (v2f_t){WIDTH + 200, 10});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(170, 250, 210, 50));
    shape->type = RECT;
    shape->body.rect = rect;
    shape->is_default = false;
    return shape;
}

static shape_t *end(void)
{
    shape_t *shape = malloc(sizeof(shape_t));

    shape->type = MIRROR;
    shape->body.offset = (v2f_t){-200, HEIGHT + 100};
    shape->is_default = false;
    return shape;
}

anim_props_t *create_anim_props_rain(void)
{
    return create_anim_props(RAIN_ANIM, NULL, start(), end());
}

anim_t *create_rain(anim_props_t *props)
{
    anim_t *anim = anim_create();

    set_anim_props(anim, props);
    anim_set_frequency(anim, 100);
    anim_set_batch_size(anim, 7);
    anim_set_duration(anim, 30);
    anim_set_speed(anim, 1000);
    anim_set_scale(anim, (v2f_t){0.5, 2});
    anim_set_color(anim, sfColor_fromRGBA(60, 70, 140, 120));
    return anim;
}
