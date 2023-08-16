/*
** EPITECH PROJECT, 2023
** src/gloop/settings/draw/settings_update_manager
** File description:
** settings update manager
*/

#include "rpg.h"

void settings_update_manager(rpg_t *rpg)
{
    settings_back_button(rpg);
    settings_music_button(rpg);
    settings_sound_button(rpg);
    settings_cancel_button(rpg);
}
