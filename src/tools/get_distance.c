/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** get_distance
*/

#include "shortcut.h"
#include <math.h>

float get_distance(v2f_t a, v2f_t b)
{
    return sqrtf(powf(b.x - a.x, 2) + powf(b.y - a.y, 2));
}
