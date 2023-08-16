/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** map_share
*/

#pragma once

    #include "data_type.h"
    #define MAPS_MAX_INDEX 3

typedef enum map_id {
    SPAWN_RED,
    FARM_RED,
    SPAWN_BLUE,
    FARM_BLUE,
    SPAWN_GREEN,
    FARM_GREEN,
    CENTER,
    CAVE
} map_id_t;

typedef struct change_map {
    data_type_t type;
    map_id_t map_id;
    map_id_t dest_map_id;
    v2f_t dest_map_pos;
    pname_t name;
} change_map_t;
