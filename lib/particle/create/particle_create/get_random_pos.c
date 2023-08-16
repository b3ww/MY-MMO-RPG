/*
** EPITECH PROJECT, 2023
** lib/particle/create/get_random_pos
** File description:
** get a random particle pos
*/

#include "particle.h"
#include <stdlib.h>

v2f_t get_random_pos(shape_t *shape)
{
    switch (shape->type) {
    case RECT:
        return get_from_rect(
            sfRectangleShape_getGlobalBounds(shape->body.rect));
    case RECT_OUTLINE:
        return sfRectangleShape_getPoint(shape->body.rect,
            rand() % sfRectangleShape_getPointCount(shape->body.rect));
    case CIRCLE:
        return get_from_circle(shape->body.circle);
    case CIRCLE_OUTLINE:
        return get_pos_from_circle_outline(shape->body.circle);
    case SPRITE:
        return get_from_rect(sfSprite_getGlobalBounds(shape->body.sprite));
    case SPRITE_CENTER:
        return get_sprite_center(shape->body.sprite);
    default:
        break;
    };
}
