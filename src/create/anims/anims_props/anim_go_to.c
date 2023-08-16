/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** anim_go_to
*/

#include "rpg_particles.h"
#include "tools.h"
#include <stdlib.h>

static shape_t *start(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, 25);
    sfCircleShape_setFillColor(circle, sfTransparent);

    shape->type = CIRCLE_OUTLINE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

static shape_t *end(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, 2);
    sfCircleShape_setFillColor(circle, sfTransparent);

    shape->type = CIRCLE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

static shape_t *part(void)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, 3);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOutlineColor(circle, sfBlack);

    shape->type = CIRCLE;
    shape->body.circle = circle;
    shape->is_default = false;
    return shape;
}

anim_props_t *create_anim_props_go_to(void)
{
    return create_anim_props(GO_TO_ANIM, part(), start(), end());
}

anim_t *create_go_to_anim(anim_props_t *props)
{
    anim_t *anim = anim_create();

    set_anim_props(anim, props);
    anim_set_frequency(anim, 1);
    anim_set_batch_size(anim, 10);
    anim_set_duration(anim, 0.1);
    anim_set_speed(anim, 95);
    anim_set_color(anim, sfColor_fromRGBA(30, 230, 70, 130));
    return anim;
}
