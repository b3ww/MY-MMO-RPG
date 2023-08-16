/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** update_me_health
*/

#include "network.h"
#include "attacked.h"
#include "tools.h"

void send_attacked(net_t *net, pname_t name, int health)
{
    attacked_t to_send;

    to_send.type = ATTACKED;
    my_strcpy(to_send.name, name);
    to_send.health = health;
    send_to_server(net, &to_send);
}

void update_me_health(net_t *network, player_t *player)
{
    if (player->stats.previous_health != player->stats.health) {
        send_attacked(network, player->name, player->stats.health);
        player->stats.previous_health = player->stats.health;
    }
}
