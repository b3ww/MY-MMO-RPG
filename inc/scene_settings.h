/*
** EPITECH PROJECT, 2023
** inc/scene_settings
** File description:
** scene_settings.h
*/

#pragma once

    #include "text.h"
    #include "button.h"
    #include "enum.h"
    #define T_COLOR 200, 200, 200, 236

//////////////
/// Struct ///
//////////////

typedef struct keys_changer {
    sfBool is_clicked;
    char base;
    char actual;
    char *str;
    text_t *text;
    sfRectangleShape *rect;
} keys_changer_t;

typedef struct scene_settings {
    sfBool is_sound;
    sfBool is_music;
    scene_t scene_before;
    text_t *title;
    text_t *title_command;
    button_t *back;
    button_t *music;
    button_t *cancel;
    button_t *sound;
    keys_changer_t *key_attack1;
    keys_changer_t *key_attack2;
    keys_changer_t *key_attack3;
    keys_changer_t *key_attack4;
    keys_changer_t *key_inventory;
    keys_changer_t *key_menu;
    keys_changer_t *key_quest;
    keys_changer_t *key_chat_open;
    keys_changer_t *key_chat_close;
} scene_settings_t;

scene_settings_t *create_settings(void);
void key_changer(scene_settings_t *settings, sfEvent evt);
void settings_button_hover(scene_settings_t *settings, sfMouseMoveEvent evt);
void settings_button_pressed(scene_settings_t *settings,
sfMouseButtonEvent evt);
void change_letter(keys_changer_t *key, char c);
