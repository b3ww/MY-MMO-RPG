/*
** EPITECH PROJECT, 2022
** evt_manager.c
** File description:
** handle evts
*/

#include "rpg.h"
#include "inv_item_share.h"

void game_event_manager(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->wd, &event)) {
        gloop_event(rpg, event);
        if (event.type == sfEvtMouseMoved)
            manage_mouse_move(rpg, rpg->game->inv, event);
        if (event.type == sfEvtMouseButtonPressed) {
            mouse_pressed_npc(rpg, event);
            manage_mouse_pressed(rpg, event);
            manage_mouse_click(rpg, event);
        }
        if (event.type == sfEvtMouseButtonReleased)
            manage_mouse_released(rpg, rpg->game->inv, event);
        if (event.type == sfEvtTextEntered)
            manage_keys_game(rpg, event.text.unicode);
    }
}
