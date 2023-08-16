/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** create_from_circle
*/

#include "particle.h"
#include <math.h>
#include <stdlib.h>

v2f_t get_pos_from_circle_outline(sfCircleShape *circle)
{
    v2f_t circle_pos = sfCircleShape_getPosition(circle);
    v2f_t point = sfCircleShape_getPoint(circle,
            rand() % (sfCircleShape_getPointCount(circle)));

    point.x += circle_pos.x;
    point.y += circle_pos.y;
    return point;
}

v2f_t get_from_circle(sfCircleShape *circle)
{
    sfVector2f random_point;
    v2f_t center = sfCircleShape_getPosition(circle);
    float radius = sfCircleShape_getRadius(circle);
    float angle = ((float)rand() / RAND_MAX) * 2 * PI;
    float r = ((float)rand() / RAND_MAX) * radius;
    sfVector2f polar = {r * cosf(angle), r * sinf(angle)};

    center.x += radius;
    center.y += radius;
    random_point = (v2f_t){center.x + polar.x, center.y + polar.y};
    return random_point;
}
