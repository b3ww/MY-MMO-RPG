/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** portals
*/

#pragma once

    #include "shortcut.h"
    #include "map_share.h"

typedef enum portal_state {
    P_IDLE,
    P_SPAWN,
    P_DESPAWN
} portal_state_t;

typedef enum portal_e{
    A,
    B,
    C,
    D
} portal_e_t;

typedef struct portal {
    sfSprite *sprite;
    sfIntRect anim_rect;
    sfClock *anim_clock;
    portal_state_t anim_state;
    map_id_t map_dest_id;
    v2f_t map_dest_spawn_pos;
    struct portal *next;
    portal_e_t id;
} portal_t;

void animate_portal(portal_t *portal);
