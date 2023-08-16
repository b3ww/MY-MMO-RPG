/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** create_splash
*/

#include "create.h"
#include "splash.h"

splash_t *create_splash(void)
{
    splash_t *splash = malloc(sizeof(splash_t));
    v2f_t size;

    splash->sprite = sfSprite_create();
    splash->texture = sfTexture_createFromFile(SPLASH_BACKGROUND, NULL);
    splash->anim_rect = (sfIntRect){0, 0, 498, 280};
    sfSprite_setTexture(splash->sprite, splash->texture, sfFalse);
    sfSprite_setTextureRect(splash->sprite, splash->anim_rect);
    sfSprite_setColor(splash->sprite, sfColor_fromRGBA(255, 255, 255, 0));
    size.x = WIDTH / sfSprite_getLocalBounds(splash->sprite).width;
    size.y = HEIGHT / sfSprite_getLocalBounds(splash->sprite).height;
    sfSprite_setScale(splash->sprite, size);
    splash->anim_clock = sfClock_create();
    splash->splash_clock = sfClock_create();
    splash->background_alpha = 0;
    return splash;
}
