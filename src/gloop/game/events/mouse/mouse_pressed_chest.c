/*
** EPITECH PROJECT, 2023
** src/gloop/game/events/mouse/mouse_pressed_chest
** File description:
** chest pressed
*/

#include "rpg.h"

static void pressed_conso_or_unconso_chest(rpg_t *rpg, sfFloatRect rect,
sfEvent evt, int i)
{
    slot_t *temp = rpg->cursor->drag;

    if (sfFloatRect_contains(&rect, evt.mouseButton.x, evt.mouseButton.y)) {
        rpg->cursor->drag = rpg->game->chest->slots[i];
        rpg->game->chest->slots[i] = temp;
    }
}

static void is_clicked_empty_slot_chest(inventory_t *chest, slot_t **drag,
sfEvent evt, int i)
{
    v2f_t pos;
    sfFloatRect rect;
    slot_t *temp = chest->slots[i];

    pos = (v2f_t){1.93 * CHEST_POS_BUTTON_X + JUMP_NEXT_ITEM * (i % 3) - 1,
        CHEST_POS_BUTTON_Y + JUMP_NEXT_ITEM_Y * (i / 3)};
    rect = (sfFloatRect){pos.x, pos.y, JUMP_NEXT_ITEM, JUMP_NEXT_ITEM};
    if (sfFloatRect_contains(&rect, evt.mouseButton.x, evt.mouseButton.y)) {
        chest->slots[i] = *drag;
        *drag = temp;
    }
}

void chest_clicked(rpg_t *rpg, sfEvent evt)
{
    sfFloatRect rect;
    item_t *it;
    conso_t *cons;

    for (int i = 0; i < 12; i++) {
        if (!rpg->game->chest->slots[i]) {
            is_clicked_empty_slot_chest(rpg->game->chest, &rpg->cursor->drag,
                evt, i);
            continue;
        }
        if (rpg->game->chest->slots[i]->type == CONSO) {
            cons = rpg->game->chest->slots[i]->slots->conso;
            rect = sfSprite_getGlobalBounds(cons->sprite);
        } else {
            it = rpg->game->chest->slots[i]->slots->unconso;
            rect = sfSprite_getGlobalBounds(it->sprite);
        }
        pressed_conso_or_unconso_chest(rpg, rect, evt, i);
    }
}
