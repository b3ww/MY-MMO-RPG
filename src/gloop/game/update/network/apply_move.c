/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** apply_move
*/

#include "rpg.h"
#include "move_share.h"
#include <stdlib.h>
#include "player.h"
#include "tools.h"

static void set_move(player_t *player, move_player_t *player_server)
{
    player->move.destination = player_server->destination;
    if (get_distance(player->move.pos, player_server->pos) > 80)
        player->move.pos = player_server->pos;
    player->move.velocity = calculate_velocity(player->move.pos,
        player->move.destination);
    player->skin.anim_state = MOVEMENT_STATE;
    sfSprite_setPosition(player->skin.sprite, player->move.pos);
}

void apply_move(net_t *network, player_t *players[50], uss_t player_count)
{
    move_player_t *player_server = ((move_player_t *)network->rdata);
    int player_id;
    int target;

    player_id = get_player_id(players, player_count, player_server->name);
    if (player_id == -1)
        return;
    set_move(players[player_id], player_server);
    set_player_direction(players[player_id]);
    target = get_player_id(players, player_count, player_server->target_name);
    if (target == -1)
        players[player_id]->fight.target = NULL;
    else
        players[player_id]->fight.target = players[target];
}
