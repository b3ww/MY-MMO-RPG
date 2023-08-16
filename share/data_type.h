/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** data_type
*/

#pragma once

    #include "shortcut.h"

    #define TYPE(element) ((head_t *)element)->type


typedef enum data_type {
    PLAYER_CONNECTION,
    PLAYER_UPDATE,
    PLAYER_LIST,
    MOVE,
    DISCONNECT_PLAYER,
    ATTACKED,
    MESSAGE_CHAT,
    CHANGE_MAP,
    MOB,
    INV,
    LIST,
    PLAYER_DIE
} data_type_t;
