/*
** EPITECH PROJECT, 2023
** src/gloop/game/events/manage_mouse_move
** File description:
** mouse move
*/

#include "rpg.h"
#include "rpg_particles.h"

static void event_update_move_state(inventory_t *inv, sfFloatRect rect,
sfEvent evt, int i)
{
    if (sfFloatRect_contains(&rect, evt.mouseMove.x, evt.mouseMove.y) &&
    (inv->slots[i]->slots->conso->state != IS_RELEASED)) {
        if (inv->slots[i]->type == CONSO)
            inv->slots[i]->slots->conso->state = IS_HOVER;
        else
            inv->slots[i]->slots->unconso->state = IS_HOVER;
    } else {
        if (inv->slots[i]->type == CONSO)
            inv->slots[i]->slots->conso->state = IS_NONE;
        else
            inv->slots[i]->slots->unconso->state = IS_NONE;
    }
}

static void generate_bin_smoke(rpg_t *rpg, sfEvent evt)
{
    if (rpg->game->bin->state == HOVER)
        return;
    rpg->game->bin->is_hover(rpg->game->bin, &evt.mouseMove);
    if (rpg->game->bin->state == HOVER) {
        anim_append(&rpg->anims, create_smoke(get_anims_props(rpg->anims_props,
            BIN_SMOKE_ANIM)));
        return;
    }
    end_smoke(rpg->anims);
}

void manage_hover_button(rpg_t *rpg, sfEvent evt)
{
    scene_game_t *game = rpg->game;

    if (game->inv->is_open) {
        generate_bin_smoke(rpg, evt);
        rpg->game->bin->is_hover(rpg->game->bin, &evt.mouseMove);
    }
    if (rpg->game->menu_in_game) {
        game->exits->is_hover(game->exits, &evt.mouseMove);
        game->load->is_hover(game->load, &evt.mouseMove);
        game->save->is_hover(game->save, &evt.mouseMove);
        game->settings->is_hover(game->settings, &evt.mouseMove);
        game->continues->is_hover(game->continues, &evt.mouseMove);
    }
    game->menu->is_hover(game->menu, &evt.mouseMove);
}

void manage_mouse_move(rpg_t *rpg, inventory_t *inv, sfEvent evt)
{
    sfFloatRect rect;
    item_t *it;
    conso_t *cons;

    manage_hover_button(rpg, evt);
    for (int i = 3; i < 12; i++) {
        if (!inv->slots[i])
            continue;
        if (inv->slots[i]->type == CONSO) {
            cons = inv->slots[i]->slots->conso;
            rect = sfSprite_getGlobalBounds(cons->sprite);
        } else {
            it = inv->slots[i]->slots->unconso;
            rect = sfSprite_getGlobalBounds(it->sprite);
        }
        if (it->state == IS_PRESSED)
            continue;
        event_update_move_state(inv, rect, evt, i);
    }
}
