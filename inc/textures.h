/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** textures
*/

#pragma once

    #include "shortcut.h"

    #define ARROW_PATH "assets/combat/arrow.png"
    #define GREEN_PORTAL_PATH "assets/entity/portals/green_portal.png"
    #define PURPLE_PORTAL_PATH "assets/entity/portals/purple_portal.png"

typedef enum texture_id {
    E_RTREE,
    E_BTREE,
    E_GTREE,
    E_RHOUSE,
    E_BHOUSE,
    E_GHOUSE,
    E_HBRIDGE,
    E_VBRIDGE,
    ARROW_TEXTURE_ID,
    GREEN_PORTAL_ID,
    PURPLE_PORTAL_ID
} texture_id_t;

typedef struct texture_list {
    uss_t id;
    sfTexture *texture;
    struct texture_list *next;
} texture_list_t;
