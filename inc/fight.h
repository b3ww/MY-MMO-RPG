/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** fight
*/

#pragma once

    #include "player.h"

    #define CRIT_MULTIPLIER 5

typedef struct attack_data {
    player_t *victim;
    player_t *attacker;
} attack_data_t;

void player_send_attack(player_t *attacker, player_t *victim);
void player_send_attack_particle(void *data);
