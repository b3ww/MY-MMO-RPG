/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** create_from_rect
*/

#include "particle.h"
#include <SFML/Graphics/Rect.h>
#include <stdlib.h>

v2f_t get_from_rect(sfFloatRect bounds)
{
    v2f_t new_pos;

    if (abs((int)bounds.width) > 1e-5)
        new_pos.x = rand() % ((int)bounds.width) + bounds.left;
    else
        new_pos.x = bounds.left;
    if (abs((int)bounds.height) > 1e-5)
        new_pos.y = rand() % ((int)bounds.height) + bounds.top;
    else
        new_pos.y = bounds.top;
    return new_pos;
}
