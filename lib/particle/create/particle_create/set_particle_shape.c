/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** set_shape_part
*/

#include "particle.h"

static void set_rect_shape(particles_t *part, anim_t *anim)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(
        anim->shape_part->body.rect);
    v2f_t center;

    center.x = bounds.width / 2;
    center.y = bounds.height / 2;
    part->shape.rect = sfRectangleShape_copy(anim->shape_part->body.rect);
    sfRectangleShape_setOrigin(part->shape.rect, center);
    sfRectangleShape_setPosition(part->shape.rect, part->position);
    sfRectangleShape_setFillColor(part->shape.rect, part->color);
    sfRectangleShape_setScale(part->shape.rect, anim->scale);
}

static void set_circle_shape(particles_t *part, anim_t *anim)
{
    float radius = sfCircleShape_getRadius(anim->shape_part->body.circle);
    v2f_t center;

    center.x = radius / 2;
    center.y = radius / 2;
    part->shape.circle = sfCircleShape_copy(anim->shape_part->body.circle);
    sfCircleShape_setOrigin(part->shape.circle, center);
    sfCircleShape_setPosition(part->shape.circle, part->position);
    sfCircleShape_setFillColor(part->shape.circle, part->color);
    sfCircleShape_setScale(part->shape.circle, anim->scale);
}

static void set_sprite_shape(particles_t *part, anim_t *anim)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        anim->shape_part->body.sprite);
    v2f_t center;

    center.x = bounds.width / 2;
    center.y = bounds.height / 2;
    part->shape.sprite = sfSprite_copy(anim->shape_part->body.sprite);
    sfSprite_setOrigin(part->shape.sprite, center);
    sfSprite_setPosition(part->shape.sprite, part->position);
    sfSprite_setScale(part->shape.sprite, anim->scale);
}

void set_shape_part(particles_t *part, anim_t *anim)
{
    v2f_t center;
    part->shape_type = anim->shape_part->type;
    switch (part->shape_type) {
    case RECT_OUTLINE:
    case RECT:
        set_rect_shape(part, anim);
        break;
    case CIRCLE_OUTLINE:
    case CIRCLE:
        set_circle_shape(part, anim);
        break;
    case SPRITE_CENTER:
    case SPRITE:
        set_sprite_shape(part, anim);
        break;
    }
}
