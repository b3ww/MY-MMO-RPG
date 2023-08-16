/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** update_ftb
*/

#include "screen_effect.h"
#include "struct.h"
#include "destroy.h"
#include "create.h"
#include "portals.h"
#include "map_share.h"
#include "tools.h"
#include "move_share.h"

void change_map(rpg_t *rpg)
{
    int id = rpg->fade_to_black->portal->map_dest_id;
    change_map_t to_send;

    to_send.type = CHANGE_MAP;
    to_send.dest_map_id = id;
    to_send.dest_map_pos = rpg->fade_to_black->portal->map_dest_spawn_pos;
    to_send.map_id = rpg->map->id;
    destroy_map(rpg->map);
    rpg->players[0]->move.pos = to_send.dest_map_pos;
    rpg->map = load_map(rpg, id);
    my_strcpy(to_send.name, rpg->players[0]->name);
    send_to_server(rpg->network, &to_send);
    rpg->player_count = 1;
}

void update_ftb(fade_to_black_t *ftb, rpg_t *rpg)
{
    sfRectangleShape_setFillColor(ftb->rect, sfColor_fromRGBA(0, 0, 0,
        ftb->alpha));
    if (ftb->active)
        ftb->alpha += 10;
    if (!ftb->active && ftb->alpha > 0) {
        ftb->alpha -= 15;
        if (ftb->alpha < 0)
            ftb->alpha = 0;
    }
    if (ftb->alpha > 255) {
        ftb->alpha = 255;
        ftb->active = false;
        change_map(rpg);
    }
}
