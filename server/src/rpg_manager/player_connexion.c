/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** player_connexion
*/

#include "rpg_online_manager.h"

static bool username_check(char *name, list_player_t *plist)
{
    if (!wstrcmp("server", name) || !wstrcmp("SERVER", name))
        return false;
    for (int i = 0; i < plist->num_player - 1; i++) {
        if (!wstrcmp(name, plist->list[i].name))
            return false;
    }
    return true;
}

void player_connexion(main_net_t *n, void *data, int *client_id)
{
    list_player_t *plist = NULL;
    chat_message_t mess; char tmp[80];

    for (int i = 0; i < 80; i++)
        tmp[i] = 0;
    mess.type = MESSAGE_CHAT;
    strcpy(mess.name, "server"); strcat(tmp, " ");
    strcat(tmp, ((player_server_t *)data)->name);
    strcat(tmp, " just connected");
    is_admin(((player_server_t *)data)->name) ? strcat(tmp, " ( ADMIN )") : 0;
    strcpy(mess.msg, tmp);
    update_player(n->clients[*client_id].players_data,
        (player_server_t *)data);
    plist = get_players_list(n, ((player_server_t *)data)->map);
    if (!username_check(((player_server_t *)data)->name, plist)) {
        dc_player(n, &n->clients[*client_id], "Username already used");
        (*client_id)--;
        return;
    } send_to_client(&n->clients[*client_id], plist);
    send_to_map(n, ((player_server_t *)data)->map,
    n->clients[*client_id].players_data); send_to_all(n, &mess);
}
