/*
** EPITECH PROJECT, 2023
** src/gloop/game/events/manage_mouse_pressed
** File description:
** mouse pressed
*/

#include "inv_item_share.h"
#include "rpg.h"
#include "tools.h"

void menu_button_pressed(scene_game_t *game, sfEvent evt)
{
    game->exits->is_pressed(game->exits, &evt.mouseButton);
    game->load->is_pressed(game->load, &evt.mouseButton);
    game->save->is_pressed(game->save, &evt.mouseButton);
    game->settings->is_pressed(game->settings, &evt.mouseButton);
    game->continues->is_pressed(game->continues, &evt.mouseButton);
}

void manage_mouse_pressed(rpg_t *rpg, sfEvent evt)
{
    manage_mouse_inventory(rpg, evt);
    if (rpg->game->menu_in_game)
        menu_button_pressed(rpg->game, evt);
    rpg->game->menu->is_pressed(rpg->game->menu, &evt.mouseButton);
    try_open_chest(rpg);
}
