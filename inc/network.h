/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** network
*/

#pragma once

    #include <SFML/Network.h>
    #include "share.h"
    #include "player.h"
    #include "struct_particle.h"
    #include "map_share.h"

    #define TSIZE 4200

typedef struct network {
    sfTcpSocket *socket;
    sfSocketSelector *selector;
    bool to_read;
    void *rdata;
    data_type_t data_type_read;
    bool to_send;
    void *sdata;
    data_type_t data_type_send;
} net_t;

net_t *create_network(sfIpAddress, uss_t port);
bool update_network(net_t *net);
void send_to_server(net_t *net, void *to_send);

void apply_move(net_t *network, player_t *players[50], uss_t player_count);
int apply_player_connection(net_t *network, player_t *players[50],
uss_t *player_count, sfFont *font);
void apply_player_update(net_t *network, player_t *players[50], uss_t *pcount);
bool remove_player_in_list(net_t *network, player_t *players[50],
uss_t *player_count);
void setup_connected_players(net_t *network, player_t *players[50],
uss_t *player_count, sfFont *font);
void update_player_health(net_t *network, player_t *players[50],
uss_t *player_count);

void update_me_health(net_t *network, player_t *player);
void send_player_connect_update(net_t *net, player_t *player,
data_type_t type, map_id_t id);
