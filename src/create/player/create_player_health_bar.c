/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** create_health_bar
*/

#include "create.h"

sfRectangleShape *create_health_bar(void)
{
    sfRectangleShape *health_bar = sfRectangleShape_create();

    sfRectangleShape_setSize(health_bar, (v2f_t){HB_MAX_WIDTH, HB_MAX_HEIGHT});
    sfRectangleShape_setOutlineThickness(health_bar, 2);
    sfRectangleShape_setFillColor(health_bar, sfRed);
    return health_bar;
}
