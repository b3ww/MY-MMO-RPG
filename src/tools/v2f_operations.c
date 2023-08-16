/*
** EPITECH PROJECT, 2022
** v2f_t_operations
** File description:
** v2f_t_operations
*/

#include "rpg.h"
#include <math.h>

v2f_t v2i_to_v2f(v2i_t vector_i)
{
    v2f_t vector_f;

    vector_f.x = vector_i.x;
    vector_f.y = vector_i.y;
    return vector_f;
}

v2f_t float_multiply_v2f(v2f_t v, float x)
{
    v2f_t new_v;
    new_v.x = v.x * x;
    new_v.y = v.y * x;
    return new_v;
}

v2f_t float_add_v2f(v2f_t v, float x)
{
    v2f_t new_v;
    new_v.x = v.x + x;
    new_v.y = v.y + x;
    return new_v;
}

v2f_t add_two_v2f(v2f_t v1, v2f_t v2)
{
    v2f_t new_v;
    new_v.x = v1.x + v2.x;
    new_v.y = v1.y + v2.y;
    return new_v;
}

float vector_norm(v2f_t vector)
{
    return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}
