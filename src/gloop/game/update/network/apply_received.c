/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** apply_received
*/

#include "rpg.h"
#include "data_type.h"
#include "rpg_player_anims.h"
#include "particle.h"
#include "create.h"
#include "chat.h"
#include "tools.h"

static void player_action(data_type_t data_type, rpg_t *rpg)
{
    switch (data_type) {
    case MOVE:
        apply_move(rpg->network, rpg->players, rpg->player_count);
        break;
    case ATTACKED:
        update_player_health(rpg->network, rpg->players, &rpg->player_count);
        break;
    case PLAYER_DIE:
        spawn_chest_when_kill(rpg->network, rpg->players[0], rpg->game,
            rpg->map->id);
        break;
    default: break;
    }
}

static void connect_update_player(rpg_t *rpg, uss_t *pcount)
{
    int player_id;

    player_id = apply_player_connection(rpg->network, rpg->players, pcount,
        rpg->font);
    anim_append(&rpg->anims, adjust_spawn_anim(rpg->anims_props,
        rpg->players[player_id]));
}

static bool connections(rpg_t *rpg, data_type_t data_type)
{
    uss_t *pcount = &rpg->player_count;

    switch (data_type) {
    case PLAYER_CONNECTION: connect_update_player(rpg, pcount); break;
    case PLAYER_UPDATE:
        apply_player_update(rpg->network, rpg->players, pcount); break;
    case PLAYER_LIST:
        setup_connected_players(rpg->network, rpg->players, pcount,
            rpg->font);
        spawn_player(rpg->players[0], rpg->textures); break;
    case DISCONNECT_PLAYER:
        if (remove_player_in_list(rpg->network, rpg->players, pcount))
            return true;
        break;
    default: break;
    }
    return false;
}

static void others(rpg_t *rpg, data_type_t data_type)
{
    char tmp[100];
    chat_message_t *msg = NULL;
    char *tmp_m = malloc(40);

    for (int i = 0; i < 100; i++)
        tmp[i] = 0;
    switch (data_type) {
    case MESSAGE_CHAT:
        msg = rpg->network->rdata;
        my_strcpy(tmp_m, msg->msg);
        parse_chat_message(rpg, msg->msg);
        my_strcat(tmp, msg->name);
        my_strcat(tmp, " :");
        my_strcat(tmp, tmp_m);
        add_to_chat(rpg->chat, tmp);
        break;
    default: break;
    }
    free(tmp_m);
}

bool apply_received(rpg_t *rpg)
{
    data_type_t data_type;

    if (rpg->network->rdata == NULL)
        return false;
    data_type = TYPE(rpg->network->rdata);
    if (connections(rpg, data_type))
        return true;
    player_action(data_type, rpg);
    others(rpg, data_type);
    return false;
}
