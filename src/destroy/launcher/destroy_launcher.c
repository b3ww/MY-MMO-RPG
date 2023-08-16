/*
** EPITECH PROJECT, 2023
** src/destroy/launcher/destroy_launcher
** File description:
** epitech > 42
*/

#include "destroy.h"

static void destroy_launcher_background(launcher_background_t background)
{
    sfTexture_destroy(background.texture_green);
    sfTexture_destroy(background.texture_red);
    sfTexture_destroy(background.texture_blue);
    sfSprite_destroy(background.sprite_green);
    sfSprite_destroy(background.sprite_red);
    sfSprite_destroy(background.sprite_blue);
}

static void destroy_ip(scene_launcher_t *launcher)
{
    destroy_text(launcher->ip_port);
    sfRectangleShape_destroy(launcher->ip_port_rect);
}

void destroy_launcher(scene_launcher_t *launcher)
{
    destroy_ip(launcher);
    destroy_button(launcher->play);
    destroy_button(launcher->exits);
    destroy_button(launcher->settings);
    destroy_button(launcher->donate);
    destroy_button(launcher->bt_left);
    destroy_button(launcher->bt_right);
    destroy_launcher_background(launcher->background);
    destroy_text(launcher->title);
    destroy_text(launcher->pseudo);
    sfRectangleShape_destroy(launcher->pseudo_rect);
    sfRectangleShape_destroy(launcher->team.team_red);
    sfRectangleShape_destroy(launcher->team.team_green);
    sfRectangleShape_destroy(launcher->team.team_blue);
    free(launcher);
}
