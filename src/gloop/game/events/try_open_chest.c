/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** try_open_chest
*/

#include "rpg.h"
#include "tools.h"

static void open_chest(rpg_t *rpg, player_t *me, chest_t *chest,
sfFloatRect area)
{
    if (get_distance(me->move.pos, (v2f_t){area.left + area.width
    / 2, area.top + area.height / 2}) < 50) {
        load_chest(rpg, rpg->game);
        chest->visited = sfTrue;
        me->move.chest = NULL;
    }
}

void try_open_chest(rpg_t *rpg)
{
    chest_t *temp = rpg->game->l_chest;
    sfFloatRect area;

    for (; temp != NULL; temp = temp->next) {
        if (temp->visited)
            continue;
        area = sfSprite_getGlobalBounds(temp->sprite);
        if (sfFloatRect_contains(&area, rpg->mpos.x, rpg->mpos.y)) {
            rpg->players[0]->move.chest = temp;
        }
        open_chest(rpg, rpg->players[0], temp, area);
    }
}
