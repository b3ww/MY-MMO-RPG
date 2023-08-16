/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** manage_mouse_inventory
*/

#include "rpg.h"
#include "inv_item_share.h"
#include "tools.h"


static void pressed_conso_or_unconso(rpg_t *rpg, sfFloatRect rect,
sfEvent evt, int i)
{
    slot_t *temp = rpg->cursor->drag;

    if (sfFloatRect_contains(&rect, evt.mouseButton.x, evt.mouseButton.y)) {
        rpg->cursor->drag = rpg->game->inv->slots[i];
        rpg->game->inv->slots[i] = temp;
    }
}

static void is_clicked_empty_slot(inventory_t *inv, slot_t **drag, sfEvent evt,
int i)
{
    v2f_t pos;
    sfFloatRect rect;
    slot_t *temp = inv->slots[i];

    if (i / 3 == 1)
        pos = (v2f_t){1.965 * INV_POS_BUTTON_X + JUMP_NEXT_ITEM * (i % 3),
            INV_POS_BUTTON_ME_1};
    if (i / 3 == 2)
        pos = (v2f_t){1.965 * INV_POS_BUTTON_X + JUMP_NEXT_ITEM * (i % 3),
            INV_POS_BUTTON_ME_2};
    if (i / 3 == 3)
        pos = (v2f_t){1.965 * INV_POS_BUTTON_X + JUMP_NEXT_ITEM * (i % 3),
            INV_POS_BUTTON_ME_3};
    rect = (sfFloatRect){pos.x, pos.y, JUMP_NEXT_ITEM, JUMP_NEXT_ITEM};
    if (sfFloatRect_contains(&rect, evt.mouseButton.x, evt.mouseButton.y)) {
        inv->slots[i] = *drag;
        *drag = temp;
    }
}

void inv_clicked(rpg_t *rpg, sfEvent evt)
{
    sfFloatRect rect;
    item_t *it;
    conso_t *cons;

    rpg->game->bin->is_pressed(rpg->game->bin, &evt.mouseButton);
    for (int i = 3; i < 12; i++) {
        if (!rpg->game->inv->slots[i]) {
            is_clicked_empty_slot(rpg->game->inv, &rpg->cursor->drag, evt, i);
            continue;
        }
        if (rpg->game->inv->slots[i]->type == CONSO) {
            cons = rpg->game->inv->slots[i]->slots->conso;
            rect = sfSprite_getGlobalBounds(cons->sprite);
        } else {
            it = rpg->game->inv->slots[i]->slots->unconso;
            rect = sfSprite_getGlobalBounds(it->sprite);
        }
        pressed_conso_or_unconso(rpg, rect, evt, i);
    }
        update_player_stat(rpg);
}

void manage_mouse_inventory(rpg_t *rpg, sfEvent evt)
{
    if (evt.mouseButton.button == sfMouseRight && rpg->cursor->drag) {
        add_to_chat(rpg->chat, rpg->cursor->drag->slots->unconso->name);
        add_to_chat(rpg->chat,
        rpg->cursor->drag->slots->unconso->description);
    }
    if (rpg->game->inv->is_open) {
        inv_clicked(rpg, evt);
        if (sfFloatRect_contains(&((sfFloatRect){INV_DELETE_BUTTON}),
            evt.mouseButton.x, evt.mouseButton.y))
            rpg->game->inv->is_open = sfFalse;
    }
    if (rpg->game->chest->is_open) {
        chest_clicked(rpg, evt);
        if (sfFloatRect_contains(&((sfFloatRect){CHEST_DELETE_BUTTON}),
            evt.mouseButton.x, evt.mouseButton.y))
            rpg->game->chest->is_open = sfFalse;
    }
}
