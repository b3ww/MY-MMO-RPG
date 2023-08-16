/*
** EPITECH PROJECT, 2023
** MMOPRG_ONLINE [SSH]
** File description:
** wnet-csfml
*/

#pragma once

    #include <SFML/Network.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "player_share.h"
    #include "disconnect.h"
    #include "map_share.h"

    #define TSIZE 4200
    #define MAX_CLIENTS 50
    #define WLOG(_str, _file) fwrite(_str, sizeof(char), sizeof(_str), _file);
    typedef unsigned short uss_t;

    typedef struct client {
        uss_t id;
        sfTcpSocket *socket;
        bool to_read;
        void *rdata;
        player_server_t *players_data;
    } client_t;

    typedef struct net {
        sfSocketSelector *selector;
        sfTcpListener *listener;
        client_t *clients;
        int num_clients;
        sfIpAddress listen_address;
        unsigned short listen_port;
        FILE *log_file;
    } main_net_t;

main_net_t *init_net_struct(uss_t port, int number_max_of_clients);
void destroy_net_struct(main_net_t *net, int number_max_of_clients);

int w_netloop(uss_t port, int ms, void (own_update(main_net_t *, void *)));

/* SELECTOR */
bool selector_is_ready(main_net_t *net);
void get_new_client(main_net_t *net);
void selector_receive(main_net_t *net, int *i);
void send_to_client(client_t *client, void *to_send);
disconnect_player_t dc_player(main_net_t *net, client_t *client, char *error);
void send_to_all(main_net_t *net, void *to_send);

/* UTILS */
void *wmcpy(const void *to_copy, size_t size);
void *memorycat(void *m1, size_t size_1, void *m2, size_t size_2);
void wstrcpy(char *dest, char const *src);
client_t *get_client_with_username(main_net_t *net, char *username);
int wstrcmp(char *s1, char *s2);
int wstrlen(char *str);
void send_to_map_w(main_net_t *net, map_id_t map, void *to_send, int cli);
