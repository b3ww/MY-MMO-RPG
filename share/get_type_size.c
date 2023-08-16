/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** get_type_size
*/

#include "disconnect.h"
#include "share.h"
#include "attacked.h"
#include "move_share.h"
#include "items_transfert.h"
#include "map_share.h"
#include "player_share.h"
#include "die_share.h"

size_t get_type_size(void *data)
{
    switch (TYPE(data)) {
    case PLAYER_CONNECTION: case PLAYER_UPDATE: return sizeof(player_server_t);
    case MOVE: return sizeof(move_player_t);
    case PLAYER_LIST: return sizeof(list_player_t);
    case DISCONNECT_PLAYER: return sizeof(disconnect_player_t);
    case ATTACKED: return sizeof(attacked_t);
    case INV: return sizeof(serv_inv_t);
    case MESSAGE_CHAT: return sizeof(chat_message_t);
    case CHANGE_MAP: return sizeof(change_map_t);
    case PLAYER_DIE: return sizeof(player_die_t);
    default:
        return 0;
    }
}
