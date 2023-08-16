/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** chest
*/

#pragma once

    #include "shortcut.h"

typedef struct chest {
    sfSprite *sprite;
    sfTexture *texture;
    sfBool visited;
    struct chest *next;
} chest_t;
