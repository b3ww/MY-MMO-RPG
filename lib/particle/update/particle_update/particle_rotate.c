/*
** EPITECH PROJECT, 2023
** lib/particle/update/particle_update/particule_rotate
** File description:
** rotation particules
*/

#include "particle.h"

void set_rotation(shape_type_t shape_type, shape_union_t shape, float rotation)
{
    switch (shape_type) {
        case RECT_OUTLINE: case RECT:
            sfRectangleShape_setRotation(shape.rect, rotation);
        case CIRCLE_OUTLINE: case CIRCLE:
            sfCircleShape_setRotation(shape.circle, rotation);
        case SPRITE_CENTER: case SPRITE:
            sfSprite_setRotation(shape.sprite, rotation);
        default: break;
    }
}

void rotate(shape_type_t shape_type, shape_union_t shape, float rotation)
{
    switch (shape_type) {
        case RECT_OUTLINE: case RECT:
            sfRectangleShape_rotate(shape.rect, rotation);
        case CIRCLE_OUTLINE: case CIRCLE:
            sfCircleShape_rotate(shape.circle, rotation);
        case SPRITE_CENTER: case SPRITE:
            sfSprite_rotate(shape.sprite, rotation);
        default: break;
    }
}
