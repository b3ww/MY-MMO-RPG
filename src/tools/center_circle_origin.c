/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** center_circle_origin
*/

#include "shortcut.h"

void center_circle_origin(sfCircleShape *circle)
{
    float radius = sfCircleShape_getRadius(circle);

    sfCircleShape_setOrigin(circle, (v2f_t){radius, radius});
}
