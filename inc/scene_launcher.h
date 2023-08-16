/*
** EPITECH PROJECT, 2023
** 4_MyMMORPG
** File description:
** launcher
*/

#pragma once

    #include "button.h"
    #include "launcher_background.h"
    #include "text.h"

    #define ARROW_BUTTON_RECT 33, 21
    #define ASSET_LAUNCH_ARROW "assets/ui/Free Platformer_UI_Buttons.png"

    #define IP_PLACEHOLDER "IP:PORT..."

typedef struct team_choice {
    sfRectangleShape *team_red;
    sfRectangleShape *team_green;
    sfRectangleShape *team_blue;
} team_choice_t;

typedef struct scene_launcher{
    button_t *play;
    button_t *settings;
    button_t *donate;
    button_t *exits;
    button_t *bt_right;
    button_t *bt_left;
    text_t *title;
    text_t *pseudo;
    sfRectangleShape *pseudo_rect;
    text_t *ip_port;
    sfRectangleShape *ip_port_rect;
    sfBool ipwr;
    sfBool is_writing;
    launcher_background_t background;
    team_choice_t team;
} scene_launcher_t;

scene_launcher_t *create_scene_launcher(void);
void launcher_button_pressed(scene_launcher_t *launcher,
sfMouseButtonEvent evt);
void launcher_button_hover(scene_launcher_t *launcher, sfMouseMoveEvent evt);
void set_pseudo(char *pseudo_str, sfText *pseudo, sfEvent evt, int size);
void create_ip_port_input(scene_launcher_t *launcher);
void write_ip_port(scene_launcher_t *launcher, sfMouseButtonEvent evt);
