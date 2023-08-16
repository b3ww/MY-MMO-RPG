/*
** EPITECH PROJECT, 2023
** src/destroy/destroy_settings
** File description:
** destroy settings
*/

#include "scene_settings.h"
#include "text.h"
#include "destroy.h"
#include <stdlib.h>

void destroy_keys_changer(keys_changer_t *key)
{
    destroy_text(key->text);
    sfRectangleShape_destroy(key->rect);
    free(key->str);
    free(key);
}

void destroy_settings(scene_settings_t *settings)
{
    destroy_keys_changer(settings->key_attack1);
    destroy_keys_changer(settings->key_attack2);
    destroy_keys_changer(settings->key_attack3);
    destroy_keys_changer(settings->key_attack4);
    destroy_keys_changer(settings->key_menu);
    destroy_keys_changer(settings->key_quest);
    destroy_keys_changer(settings->key_inventory);
    destroy_keys_changer(settings->key_chat_open);
    destroy_keys_changer(settings->key_chat_close);
    destroy_button(settings->back);
    destroy_button(settings->music);
    destroy_button(settings->sound);
    destroy_button(settings->cancel);
    destroy_text(settings->title);
    destroy_text(settings->title_command);
    free(settings);
}
