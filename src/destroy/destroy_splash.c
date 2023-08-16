/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** destroy_splash
*/

#include "destroy.h"

void destroy_splash(splash_t *splash)
{
    if (splash == NULL)
        return;
    sfClock_destroy(splash->anim_clock);
    sfClock_destroy(splash->splash_clock);
    sfSprite_destroy(splash->sprite);
    sfTexture_destroy(splash->texture);
    free(splash);
}
