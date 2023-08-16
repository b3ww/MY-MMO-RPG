/*
** EPITECH PROJECT, 2023
** src/gloop/settings/settings_manager
** File description:
** settings manager
*/

#include "rpg.h"

void settings_manager(rpg_t *rpg)
{
    settings_event_manager(rpg);
    settings_update_manager(rpg);
    settings_draw_manager(rpg);
}
