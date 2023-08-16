/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** share
*/

#pragma once

    #include "data_type.h"
    #include "map_share.h"
    #include "player_share.h"

typedef struct move_player {
    data_type_t type;
    pname_t name;
    map_id_t map;
    v2f_t pos;
    int speed;
    v2f_t destination;
    pname_t target_name;
    anim_state_t anim_state;
} move_player_t;
