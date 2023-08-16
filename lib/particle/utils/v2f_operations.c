/*
** EPITECH PROJECT, 2022
** v2f_operations
** File description:
** v2f_operations
*/

#include "particle.h"

v2f_t float_multiply_v2f_part(v2f_t v, float x)
{
    v2f_t new_v;

    new_v.x = v.x * x;
    new_v.y = v.y * x;
    return new_v;
}

v2f_t add_two_v2f_part(v2f_t v1, v2f_t v2)
{
    v2f_t new_v;

    new_v.x = v1.x + v2.x;
    new_v.y = v1.y + v2.y;
    return new_v;
}

int contain_v2f(v2f_t min, v2f_t max, v2f_t ele)
{
    if (ele.x >= min.x && ele.x <= max.x && ele.y >= min.y && ele.y <= max.y)
        return 1;
    return 0;
}
