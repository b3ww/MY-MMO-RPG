/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** destroy_shape
*/

#include "particle.h"
#include <stdlib.h>

void destroy_shape(shape_t *shape)
{
    if (shape == NULL)
        return;
    switch (shape->type) {
    case RECT_OUTLINE: case RECT:
        sfRectangleShape_destroy(shape->body.rect);
        break;
    case CIRCLE_OUTLINE: case CIRCLE:
        sfCircleShape_destroy(shape->body.circle);
        break;
    case SPRITE_CENTER: case SPRITE:
        sfSprite_destroy(shape->body.sprite);
        break;
    default:
        break;
    }
    free(shape);
}

void destroy_shape_part(shape_type_t shape_type, shape_union_t shape)
{
    switch (shape_type) {
    case RECT_OUTLINE: case RECT:
        sfRectangleShape_destroy(shape.rect);
        break;
    case CIRCLE_OUTLINE: case CIRCLE:
        sfCircleShape_destroy(shape.circle);
        break;
    case SPRITE_CENTER: case SPRITE:
        sfSprite_destroy(shape.sprite);
        break;
    default:
        break;
    }
}
