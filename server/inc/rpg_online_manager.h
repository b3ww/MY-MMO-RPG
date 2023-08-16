/*
** EPITECH PROJECT, 2023
** MMOPRG_ONLINE [SSH]
** File description:
** rpg_online
*/

#pragma once

    #include "../../share/share.h"
    #include "wcsv.h"
    #include "wnetcsfml.h"
    #include "move_share.h"
    #include "attacked.h"

    #define NCLIENT(net, name) get_client_with_username(net, name)
    #define UPH(net, dt) NCLIENT(net, ((attacked_t *)dt)->name)
    #define UPM(pdata, data) update_player_move(pdata, (move_player_t *)data)
    #define DTA(data) ((attacked_t *)data)->health
    #define ITEMS_CF "config/items_conf.csv"

typedef struct manager {
    wcsv_t *items_csv;
    char ***chest;
} manager_t;

typedef struct score {
    data_type_t type;
    pname_t name;
    uss_t score;
} score_t;

void rpg_online_manager(main_net_t *net, void *);
void update_player(player_server_t *dest, player_server_t *src);
void player_connexion(main_net_t *n, void *data, int *client_id);
void move_player_map(main_net_t *net, int client_id, change_map_t *data);
void update_player_move(player_server_t *dest, move_player_t *src);
void read_data(main_net_t *net, int *client_id);
list_player_t *get_players_list(main_net_t *net, map_id_t map_id);
manager_t *init_manager(void);
char **wstr_to_word_array(char *str, char *sample);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
int wstrlen(char *str);
char **wrtab_copy(char **tab);
char *skip_ws(char *str);
bool percent(int value);

void send_to_map(main_net_t *net, map_id_t map, void *to_send);
void send_to_map_w(main_net_t *net, map_id_t map, void *to_send, int cli);
bool is_admin(char *to_find);
char *intToString(int num);
void quickSort(score_t* arr, int low, int high);