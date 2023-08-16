/*
** EPITECH PROJECT, 2023
** 4_MyMMORPG
** File description:
** launcher_event_manager
*/

#include "rpg.h"
#include <SFML/Window.h>

static void mouse_event(scene_launcher_t *launcher, sfEvent event,
player_t *player)
{
    if (event.type == sfEvtMouseMoved)
        launcher_button_hover(launcher, event.mouseMove);
    if (event.type == sfEvtMouseButtonPressed)
        launcher_button_pressed(launcher, event.mouseButton);
    if (event.type == sfEvtMouseButtonReleased)
        launcher_button_released(player, launcher, event.mouseButton);
}

static void press_enter_to_start(rpg_t *rpg, scene_launcher_t *launcher,
sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter) {
        launcher->play->state = PRESSED;
        launcher_button_released(rpg->players[0], launcher,
            (sfMouseButtonEvent){sfEvtMouseButtonReleased, sfMouseLeft,
            1870, 1000});
    }
}

static void detect_paste(sfEvent ev, scene_launcher_t *launcher)
{
    const char *clipboard = sfClipboard_getString();

    if (ev.type == sfEvtKeyPressed && (sfKeyboard_isKeyPressed(sfKeyLControl)
    || sfKeyboard_isKeyPressed(sfKeyRControl)) &&
    sfKeyboard_isKeyPressed(sfKeyV)) {
        if (launcher->is_writing && strlen(clipboard) <
        launcher->pseudo->max_length - strlen(launcher->pseudo->str)) {
            strcat(launcher->pseudo->str, clipboard);
        } if (launcher->ipwr && strlen(clipboard) <
        launcher->ip_port->max_length - strlen(launcher->ip_port->str)) {
            strcat(launcher->ip_port->str, clipboard);
        }
    }
}

void launcher_event_manager(rpg_t *rpg)
{
    sfEvent ev;
    scene_launcher_t *lncher = rpg->launcher;

    while (sfRenderWindow_pollEvent(rpg->wd, &ev)) {
        gloop_event(rpg, ev);
        mouse_event(lncher, ev, rpg->players[0]);
        detect_paste(ev, lncher);
        if (ev.type == sfEvtTextEntered && lncher->is_writing == sfTrue)
            set_pseudo(lncher->pseudo->str, lncher->pseudo->text, ev, 17);
        if (ev.type == sfEvtTextEntered && lncher->ipwr == sfTrue)
            set_pseudo(lncher->ip_port->str, lncher->ip_port->text, ev, 26);
        if (ev.type == sfEvtKeyPressed && !lncher->is_writing && !lncher->ipwr)
            set_player_class(rpg->players[0], ev.key.code);
        if (ev.type == sfEvtKeyPressed && lncher->is_writing == sfTrue)
            set_text_move(lncher->pseudo->str, lncher->pseudo->text);
        if (ev.type == sfEvtKeyPressed && lncher->ipwr == sfTrue)
            set_text_move(lncher->ip_port->str, lncher->ip_port->text);
        press_enter_to_start(rpg, lncher, ev);
    }
}
