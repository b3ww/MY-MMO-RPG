/*
** EPITECH PROJECT, 2023
** src/gloop/settings/event/settings_events_manager
** File description:
** settings events manager
*/

#include "rpg.h"
#include "scene_settings.h"

void settings_event_manager(rpg_t *rpg)
{
    sfEvent evt;

    while (sfRenderWindow_pollEvent(rpg->wd, &evt)) {
        gloop_event(rpg, evt);
        if (evt.type == sfEvtMouseMoved)
            settings_button_hover(rpg->settings, evt.mouseMove);
        if (evt.type == sfEvtMouseButtonPressed)
            settings_button_pressed(rpg->settings, evt.mouseButton);
        if (evt.type == sfEvtMouseButtonReleased)
            settings_button_released(rpg->settings, evt.mouseButton);
        if (evt.type == sfEvtTextEntered)
            key_changer(rpg->settings, evt);
    }
}
