/*
** EPITECH PROJECT, 2023
** 4_MyMMORPG
** File description:
** gloop
*/

#include "audio_manager.h"
#include "rpg.h"

void gloop(rpg_t *rpg)
{
    play_music(rpg->audio_manager, "menu");
    while (sfRenderWindow_isOpen(rpg->wd)) {
        gloop_update_manager(rpg);
        switch (rpg->scene) {
        case SPLASH: splash_manager(rpg); break;
        case LAUNCHER: launcher_manager(rpg); break;
        case GAME: game_manager(rpg); break;
        case SETTINGS: settings_manager(rpg); break;
        default: break;
        }
    }
}
