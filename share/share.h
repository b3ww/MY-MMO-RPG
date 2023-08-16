/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** share
*/

#pragma once

    #include "data_type.h"

    #define NB_CHEST 5

typedef struct head {
    data_type_t type;
} head_t;

//  FIGHT_ACTION
typedef enum attack_type {
    SWORD_HIT,
    BOW,
    FIREBALL
} attack_type_t;

//  MOB
typedef enum mob_cass {
    SLIME,
    ZOMBIE,
    CREEPER
} mob_class_t;

typedef struct chat_message {
    data_type_t type;
    pname_t name;
    char msg[40];
} chat_message_t;

size_t get_type_size(void *data);
