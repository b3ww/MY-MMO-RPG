/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** destroy_npc
*/

#include "player.h"
#include "struct.h"
#include "map.h"

void destroy_npc(rpg_t *rpg)
{
    npc_t *npc = rpg->npc;

    sfClock_destroy(npc->anim_clock);
    sfTexture_destroy(npc->texture);
    sfSprite_destroy(npc->sprite);
    free(npc);
}
