/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** create_npc
*/

#include "player.h"
#include "struct.h"
#include "map.h"

static void set_capy_pos(npc_t *npc)
{
    npc->capy[0].id_map = SPAWN_RED;
    npc->capy[0].pos.x = TILE_WIDTH * 4 + TILE_WIDTH / 2;
    npc->capy[0].pos.y = TILE_HEIGHT * 4;
    npc->capy[1].id_map = SPAWN_BLUE;
    npc->capy[1].pos.x = TILE_WIDTH * 3 + TILE_WIDTH / 2;
    npc->capy[1].pos.y = TILE_HEIGHT * 3;
    npc->capy[2].id_map = SPAWN_GREEN;
    npc->capy[2].pos.x = TILE_WIDTH * 10 + TILE_WIDTH / 2;
    npc->capy[2].pos.y = TILE_HEIGHT * 3;
}

npc_t *load_npc(void)
{
    npc_t *npc = malloc(sizeof(npc_t));

    sfTexture *texture = sfTexture_createFromFile(CAPY_PATH, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    set_capy_pos(npc);
    npc->texture = texture;
    npc->is_here = 1;
    npc->sprite = sprite;
    sfSprite_setScale(npc->sprite, (v2f_t){3, 3});
    npc->anim_clock = sfClock_create();
    npc->anim_rect = (sfIntRect){0, 0, 21, 28};
    sfSprite_setTextureRect(npc->sprite, npc->anim_rect);
    return npc;
}
