/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski [SSH: 193.70.40.62]
** File description:
** read_data
*/

#include "wnetcsfml.h"
#include "move_share.h"
#include "attacked.h"
#include "rpg_online_manager.h"

static void player_action(main_net_t *net, int *client_id, int data_type,
void *data)
{
    if (data_type == MOVE || data_type == ATTACKED)
        send_to_map(net, ((player_server_t *)net->clients[*client_id]
        .players_data)->map, data);
    switch (data_type) {
    case MOVE: UPM(net->clients[*client_id].players_data, data); break;
    case ATTACKED: UPH(net, data)->players_data->health = DTA(data); break;
    case PLAYER_UPDATE:
        update_player(net->clients[*client_id].players_data,
            (player_server_t *)data);
        send_to_map(net, ((player_server_t *)data)->map,
            net->clients[*client_id].players_data);
        break;
    default: break;
    }
}

bool is_admin(char *to_find)
{
    char **admins = wstr_to_word_array(open_file("config/admin.csv"), " ,");

    if (!admins)
        return false;
    for (int i= 0; admins[i]; i++) {
        if (!wstrcmp(admins[i], to_find)) {
            TABFREE(admins);
            free(admins);
            return true;
        }
    }
    TABFREE(admins);
    free(admins);
    return false;
}

void send_msg(main_net_t *net, char *name, char *msg, int client_id)
{
    chat_message_t to_send;

    for (int i = 0; i < 20; i++)
        to_send.name[i] = 0;
    for (int i = 0; i < 40; i++)
        to_send.msg[i] = 0;
    if (wstrlen(name) > 20 || wstrlen(msg) > 40)
        return;
    strcpy(to_send.name, name);
    strcat(to_send.msg, " ");
    strcat(to_send.msg, msg);
    to_send.type = MESSAGE_CHAT;
    send_to_client(&net->clients[client_id], &to_send);
}

void manage_chat(main_net_t *net, chat_message_t *data, int client_id)
{
    score_t scores[50];

    if (data->msg[1] != '/') {
        send_to_all(net, net->clients[client_id].rdata);
        return;
    }
    if (!strcmp(data->msg, " /scores") || !strcmp(data->msg, " /SCORES")) {
        for (int i = 0; i < net->num_clients; i++) {
            strcpy(scores[i].name, net->clients[i].players_data->name);
            scores[i].score = net->clients[i].players_data->kill_count;
        }
        quickSort(scores, 0, net->num_clients - 1);
        send_msg(net, "SERVER", "SCORE-BOARD :", client_id);
        for (int i = 0; i < net->num_clients && i < 7; i++)
            send_msg(net, net->clients[i].players_data->name,
            intToString(net->clients[i].players_data->kill_count), client_id);
        return;
    }
    if (is_admin(data->name))
        send_to_all(net, net->clients[client_id].rdata);
}

void read_data(main_net_t *net, int *client_id)
{
    void *data = net->clients[*client_id].rdata;
    int data_type = TYPE(data);
    char tmp[80];

    for (int i = 0; i < 80; i++)
        tmp[i] = 0;
    net->clients[*client_id].to_read = false;
    player_action(net, client_id, data_type, data);
    switch (data_type) {
    case PLAYER_CONNECTION: player_connexion(net, data, client_id); break;
    case MESSAGE_CHAT: manage_chat(net, data, *client_id); break;
    case CHANGE_MAP: move_player_map(net, *client_id, data); break;
    case PLAYER_DIE:
    case DISCONNECT_PLAYER: send_to_map(net,
        net->clients[*client_id].players_data->map, data); strcat(tmp, " ");
        strcat(tmp, net->clients[*client_id].players_data->name);
        strcat(tmp, " just disconnected");
        for (int i = 0; i < net->num_clients; i++)
            send_msg(net, "SERVER", tmp, i); break;
    }
}
