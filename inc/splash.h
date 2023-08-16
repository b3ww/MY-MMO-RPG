/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** splash
*/

#pragma once

    #include "shortcut.h"

    #define SPLASH_BACKGROUND "assets/background/splash_midnight.png"

typedef struct splash {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *anim_clock;
    sfClock *splash_clock;
    sfUint8 background_alpha;
    sfIntRect anim_rect;
} splash_t;
