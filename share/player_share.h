/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** player_share
*/

#pragma once

    #include "data_type.h"
    #include "map_share.h"
    #include "player_class.h"

typedef enum anim_state {
    IDLE_STATE,
    MOVEMENT_STATE,
    ATTACK_STATE,
    DEATH_STATE
} anim_state_t;

typedef enum player_color {
    RED,
    GREEN,
    BLUE
} player_color_t;

typedef enum player_fight_range {
    MELEE,
    RANGE
} player_range_t;

typedef struct player_server {
    data_type_t type;
    int id;
    pname_t name;
    int max_health;
    int health;
    int regen;
    int max_mana;
    int mana;
    uss_t level;
    int exp;
    player_class_t player_class;
    player_color_t color;
    v2f_t pos;
    v2f_t velocity;
    v2f_t destination;
    int speed;
    anim_state_t anim_state;
    player_range_t range_type;
    unsigned int range;
    unsigned int attack_damage;
    float attack_speed;
    int projectile_speed;
    uss_t kill_count;
    map_id_t map;
} player_server_t;

typedef struct list_player {
    data_type_t type;
    int num_player;
    player_server_t list[50];
} list_player_t;
