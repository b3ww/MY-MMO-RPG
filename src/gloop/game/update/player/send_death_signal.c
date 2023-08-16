/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** send_death_signal
*/

#include "player.h"
#include "network.h"
#include "die_share.h"
#include "tools.h"
#include "destroy.h"

bool send_death_signal(player_t *player, net_t *network)
{
    player_die_t die;
    if (player->skin.anim_state == DEATH_STATE && player->skin.anim_rect.left
    == 32 * 3) {
        die.type = PLAYER_DIE;
        my_strcpy(die.name, player->name);
        my_strcpy(die.killer, player->fight.hited_by);
        die.pos = player->move.pos;
        send_to_server(network, &die);
        return true;
    }
    return false;
}
