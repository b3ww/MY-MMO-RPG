/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** cursor
*/

#pragma once

    #include "shortcut.h"
    #include "inventory.h"
    #include <SFML/Graphics.h>

typedef enum cursor_type {
    ARROW,
    SELECT,
    SELECT_TAP
} cursor_type_t;

typedef struct cursor {
    sfSprite *sprite;
    cursor_type_t type;
    sfTexture *textures[3];
    slot_t *drag;
    v2f_t hotspots[3];
} cursor_t;
