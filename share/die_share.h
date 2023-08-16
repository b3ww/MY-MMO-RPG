/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** die_share
*/

#pragma once

    #include "data_type.h"
    #include "player_class.h"

typedef struct player_die {
    data_type_t type;
    pname_t name;
    v2f_t pos;
    pname_t killer;
} player_die_t;
