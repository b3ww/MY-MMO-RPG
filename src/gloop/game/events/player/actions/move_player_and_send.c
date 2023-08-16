/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** move_player_and_send
*/

#include "rpg.h"
#include "move_share.h"
#include "tools.h"
#include "rpg_player_anims.h"
#include "v2f_operations.h"

void move_player_and_send(rpg_t *rpg)
{
    move_player_t move;
    player_t *player = rpg->players[0];

    move.type = MOVE;
    move.pos = player->move.pos;
    move.destination.x = rpg->mpos.x;
    move.destination.y = rpg->mpos.y;
    move.speed = player->move.speed;
    move.anim_state = MOVEMENT_STATE;
    my_strcpy(move.target_name, player->fight.target == NULL ? NOBODY :
        player->fight.target->name);
    my_strcpy(move.name, player->name);
    move.map = rpg->map->id;
    if (player->fight.target == NULL || player->skin.anim_state
    != ATTACK_STATE) {
        anim_append(&player->anims, adjust_go_to_anim(rpg->anims_props,
            v2i_to_v2f(rpg->mpos), rpg->target_player));
        send_to_server(rpg->network, &move);
    }
}
