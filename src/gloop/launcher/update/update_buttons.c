/*
** EPITECH PROJECT, 2023
** game/update_buttons
** File description:
** game update
*/

#include "rpg.h"
#include "tools.h"
#include "donate.h"

static void update_play_button_launcher(rpg_t *rpg, scene_launcher_t *launcher)
{
    switch (launcher->play->state) {
        case HOVER: sfSprite_setTextureRect(launcher->play->sprite,
                (sfIntRect){BUTTON_JUMP, 0, SIZE_PLAY_BUTTON}); break;
        case PRESSED: sfSprite_setTextureRect(launcher->play->sprite,
                (sfIntRect){2 * BUTTON_JUMP, 0, SIZE_PLAY_BUTTON}); break;
        case RELEASED: sfSprite_setTextureRect(launcher->play->sprite,
                (sfIntRect){BUTTON_JUMP, 0, SIZE_PLAY_BUTTON});
            launcher->play->state = HOVER;
            if (launcher->ip_port->str[0])
                update_network_infos(rpg, launcher->ip_port->str);
            play_button_clicked(rpg);
            break;
        default: sfSprite_setTextureRect(launcher->play->sprite,
            (sfIntRect){0, 0, SIZE_PLAY_BUTTON}); break;
    }
}

void update_settings_button_launcher(rpg_t *rpg, button_t *settings,
scene_t scene)
{
    switch (settings->state) {
        case HOVER: sfSprite_setTextureRect(settings->sprite,
                (sfIntRect){BUTTON_JUMP, 0, SIZE_SETTINGS_BUTTON}); break;
        case PRESSED: sfSprite_setTextureRect(settings->sprite,
                (sfIntRect){2 * BUTTON_JUMP, 0, SIZE_SETTINGS_BUTTON}); break;
        case RELEASED: sfSprite_setTextureRect(settings->sprite,
                (sfIntRect){BUTTON_JUMP, 0, SIZE_SETTINGS_BUTTON});
            settings->state = HOVER;
            rpg->settings->scene_before = scene;
            rpg->scene = SETTINGS;
            break;
        default: sfSprite_setTextureRect(settings->sprite,
            (sfIntRect){0, 0, SIZE_SETTINGS_BUTTON}); break;
    }
}

static void update_donate_button_launcher(scene_launcher_t *launcher)
{
    switch (launcher->donate->state) {
        case HOVER: sfSprite_setTextureRect(launcher->donate->sprite,
                (sfIntRect){BUTTON_JUMP, 0, SIZE_DONATE_BUTTON}); break;
        case PRESSED: sfSprite_setTextureRect(launcher->donate->sprite,
                (sfIntRect){2 * BUTTON_JUMP, 0, SIZE_DONATE_BUTTON}); break;
        case RELEASED: sfSprite_setTextureRect(launcher->donate->sprite,
                (sfIntRect){BUTTON_JUMP, 0, SIZE_DONATE_BUTTON});
            launcher->donate->state = HOVER;
            system(DONATE_LINK);
            break;
        default: sfSprite_setTextureRect(launcher->donate->sprite,
            (sfIntRect){0, 0, SIZE_DONATE_BUTTON}); break;
    }
}

void update_exits_button_launcher(rpg_t *rpg, button_t *exits)
{
    switch (exits->state) {
        case HOVER: sfSprite_setTextureRect(exits->sprite,
                (sfIntRect){BUTTON_JUMP, 0, SIZE_EXIT_BUTTON}); break;
        case PRESSED: sfSprite_setTextureRect(exits->sprite,
                (sfIntRect){2 * BUTTON_JUMP, 0, SIZE_EXIT_BUTTON}); break;
        case RELEASED: sfSprite_setTextureRect(exits->sprite,
                (sfIntRect){BUTTON_JUMP, 0, SIZE_EXIT_BUTTON});
            exits->state = HOVER;
            sfRenderWindow_close(rpg->wd);
            break;
        default: sfSprite_setTextureRect(exits->sprite,
            (sfIntRect){0, 0, SIZE_EXIT_BUTTON}); break;
    }
}

void update_buttons(rpg_t *rpg)
{
    update_play_button_launcher(rpg, rpg->launcher);
    update_settings_button_launcher(rpg, rpg->launcher->settings, LAUNCHER);
    update_exits_button_launcher(rpg, rpg->launcher->exits);
    update_donate_button_launcher(rpg->launcher);
    update_right_button_launcher(rpg, rpg->launcher);
    update_left_button_launcher(rpg, rpg->launcher);
}
