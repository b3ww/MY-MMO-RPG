/*
** EPITECH PROJECT, 2023
** src/gloop/game/draw/draw_items
** File description:
** draw_items
*/

#include "rpg.h"

static void place_sprite_item(slot_t *slots, int i)
{
    if (i / 3 == 1)
        sfSprite_setPosition(slots->slots->unconso->sprite,
            (v2f_t){1.965 * INV_POS_BUTTON_X + JUMP_NEXT_ITEM * (i % 3),
            INV_POS_BUTTON_ME_1});
    if (i / 3 == 2)
        sfSprite_setPosition(slots->slots->unconso->sprite,
            (v2f_t){1.965 * INV_POS_BUTTON_X + JUMP_NEXT_ITEM * (i % 3),
            INV_POS_BUTTON_ME_2});
    if (i / 3 == 3)
        sfSprite_setPosition(slots->slots->unconso->sprite,
            (v2f_t){1.965 * INV_POS_BUTTON_X + JUMP_NEXT_ITEM * (i % 3),
            INV_POS_BUTTON_ME_3});
}

static void slots_drawing(rpg_t *rpg, inventory_t *inv, int i)
{
    v2f_t pos;

    if (!inv->slots[i])
        return;
    pos = sfSprite_getPosition(inv->slots[i]->slots->unconso->sprite);
    sfSprite_setPosition(inv->slot_sp, pos);
    place_sprite_item(inv->slots[i], i);
    sfRenderWindow_drawSprite(rpg->wd, inv->slot_sp, NULL);
    sfRenderWindow_drawSprite(rpg->wd,
        inv->slots[i]->slots->unconso->sprite, NULL);
}

static void place_sprite_item_chest(slot_t *slots, int i)
{
    sfSprite_setPosition(slots->slots->unconso->sprite,
        (v2f_t){1.93 * CHEST_POS_BUTTON_X + JUMP_NEXT_ITEM * (i % 3) - 1,
        CHEST_POS_BUTTON_Y + JUMP_NEXT_ITEM_Y * (i / 3)});
}

static void slots_drawing_chest(rpg_t *rpg, inventory_t *chest, int i)
{
    v2f_t pos;

    if (!chest->slots[i])
        return;
    pos = sfSprite_getPosition(chest->slots[i]->slots->unconso->sprite);
    sfSprite_setPosition(chest->slot_sp, pos);
    place_sprite_item_chest(chest->slots[i], i);
    sfRenderWindow_drawSprite(rpg->wd, chest->slot_sp, NULL);
    sfRenderWindow_drawSprite(rpg->wd,
        chest->slots[i]->slots->unconso->sprite, NULL);
}

void draw_items(rpg_t *rpg, inventory_t *inv, inventory_t *chest)
{
    if (rpg->game->inv->is_open) {
        sfRenderWindow_drawSprite(rpg->wd, rpg->game->inv->sprite, NULL);
        sfRenderWindow_drawSprite(rpg->wd, rpg->game->bin->sprite, NULL);
        for (int i = 3; i < 12; i++) {
            slots_drawing(rpg, inv, i);
        }
    }
    if (rpg->game->chest->is_open) {
        sfRenderWindow_drawSprite(rpg->wd, rpg->game->chest->sprite, NULL);
        for (int i = 0; i < 12; i++) {
            slots_drawing_chest(rpg, chest, i);
        }
    }
}
