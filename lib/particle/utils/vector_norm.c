/*
** EPITECH PROJECT, 2022
** vector_norm
** File description:
** vector_norm
*/

#include "particle.h"
#include <math.h>

float vector_norm(v2f_t vector)
{
    return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}
