/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** calculate_velocity
*/

#include "rpg.h"
#include "v2f_operations.h"

v2f_t calculate_velocity(v2f_t start, v2f_t end)
{
    v2f_t dir = {end.x - start.x, end.y - start.y};

    return float_multiply_v2f(dir, 1 / vector_norm(dir));
}
