/*
** EPITECH PROJECT, 2023
** src/gloop/game/events/manage_mouse_released
** File description:
** released item
*/

#include "rpg.h"

static void event_update_released_state(inventory_t *inv, int i)
{
    if (inv->slots[i]->slots->unconso->state == IS_PRESSED) {
        if (inv->slots[i]->type == CONSO) {
            inv->slots[i]->slots->conso->state = IS_RELEASED;
        } else
            inv->slots[i]->slots->unconso->state = IS_RELEASED;
    }
}

static void manage_button_released(scene_game_t *game, sfEvent evt)
{
    if (game->inv->is_open)
        game->bin->is_released(game->bin, &evt.mouseButton);
    if (game->menu_in_game) {
        game->exits->is_released(game->exits, &evt.mouseButton);
        game->load->is_released(game->load, &evt.mouseButton);
        game->save->is_released(game->save, &evt.mouseButton);
        game->settings->is_released(game->settings, &evt.mouseButton);
        game->continues->is_released(game->continues, &evt.mouseButton);
    }
    game->menu->is_released(game->menu, &evt.mouseButton);
}

void manage_mouse_released(rpg_t *rpg, inventory_t *inv, sfEvent evt)
{
    item_t *it;
    conso_t *cons;

    manage_button_released(rpg->game, evt);
    for (int i = 3; i < 12; i++) {
        if (!inv->slots[i])
            continue;
        if (inv->slots[i]->type == CONSO) {
            cons = inv->slots[i]->slots->conso;
            cons = cons;
        } else {
            it = inv->slots[i]->slots->unconso;
            it = it;
        }
        event_update_released_state(inv, i);
    }
}
