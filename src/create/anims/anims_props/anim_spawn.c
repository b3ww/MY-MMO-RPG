/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_spawn
*/

#include "rpg_particles.h"
#include "tools.h"
#include <stdlib.h>

static shape_t *start(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, 2);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setPosition(circle, (v2f_t){150, 150});

    shape->type = CIRCLE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

static shape_t *end(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, 40);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setPosition(circle, (v2f_t){100, 100});

    shape->type = CIRCLE_OUTLINE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

static shape_t *part(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, 6);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 2);
    sfCircleShape_setOutlineColor(circle, sfBlack);

    shape->type = CIRCLE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

anim_props_t *create_anim_props_spawn(void)
{
    return create_anim_props(SPAWN_ANIM, part(), start(), end());
}

anim_t *create_spawn_anim(anim_props_t *props)
{
    anim_t *anim = anim_create();

    set_anim_props(anim, props);
    anim_set_frequency(anim, 6);
    anim_set_batch_size(anim, 14);
    anim_set_duration(anim, 0.2);
    anim_set_speed(anim, 150);
    anim_set_color(anim, sfColor_fromRGBA(200, 30, 30, 180));
    return anim;
}
