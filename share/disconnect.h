/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski [SSH: 193.70.40.62]
** File description:
** requests
*/

#pragma once

    #include "data_type.h"

typedef struct disconnect_player {
    data_type_t type;
    pname_t name;
    char why[144];
} disconnect_player_t;
