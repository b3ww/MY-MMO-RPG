/*
** EPITECH PROJECT, 2023
** 4_MyMMORPG
** File description:
** launcher_manager
*/

#include "scene_launcher.h"
#include "rpg.h"
#include "audio_manager.h"

void launcher_manager(rpg_t *rpg)
{
    launcher_event_manager(rpg);
    launcher_update_manager(rpg);
    launcher_draw_manager(rpg);
}
