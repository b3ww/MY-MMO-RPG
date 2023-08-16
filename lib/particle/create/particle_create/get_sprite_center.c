/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** get_sprite_center
*/

#include "particle.h"

v2f_t get_sprite_center(sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    v2f_t center;

    center.x = bounds.left + bounds.width / 2;
    center.y = bounds.top + bounds.height / 2;
    return center;
}
