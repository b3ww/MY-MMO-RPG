/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** screen_effect
*/

#pragma once

    #include "shortcut.h"
    #include "portals.h"

typedef struct fade_to_black {
    sfRectangleShape *rect;
    short alpha;
    bool active;
    portal_t *portal;
} fade_to_black_t;
