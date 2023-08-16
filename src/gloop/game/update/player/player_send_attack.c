/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** particle_received
*/

#include "fight.h"
#include <stdlib.h>
#include "tools.h"

void player_send_attack(player_t *attacker, player_t *victim)
{
    unsigned int damage = attacker->fight.attack_damage;

    victim->stats.health -= damage;
    my_strcpy(victim->fight.hited_by, attacker->name);
}

void player_send_attack_particle(void *data)
{
    attack_data_t *attack = (attack_data_t *)data;

    player_send_attack(attack->attacker, attack->victim);
}
