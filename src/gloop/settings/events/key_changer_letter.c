/*
** EPITECH PROJECT, 2023
** src/gloop/settings/events/key_changer_lette
** File description:
** changing key
*/

#include "scene_settings.h"
#include "tools.h"

void change_letter(keys_changer_t *key, char c)
{
    key->actual = c;
    key->str[my_strlen(key->str) - 1] = key->actual;
    sfText_setString(key->text->text, key->str);
}

void key_changer(scene_settings_t *settings, sfEvent evt)
{
    if (settings->key_attack1->is_clicked)
        change_letter(settings->key_attack1, evt.text.unicode);
    if (settings->key_attack2->is_clicked)
        change_letter(settings->key_attack2, evt.text.unicode);
    if (settings->key_attack3->is_clicked)
        change_letter(settings->key_attack3, evt.text.unicode);
    if (settings->key_attack4->is_clicked)
        change_letter(settings->key_attack4, evt.text.unicode);
    if (settings->key_menu->is_clicked)
        change_letter(settings->key_menu, evt.text.unicode);
    if (settings->key_inventory->is_clicked)
        change_letter(settings->key_inventory, evt.text.unicode);
    if (settings->key_quest->is_clicked)
        change_letter(settings->key_quest, evt.text.unicode);
    if (settings->key_chat_open->is_clicked)
        change_letter(settings->key_chat_open, evt.text.unicode);
    if (settings->key_chat_close->is_clicked)
        change_letter(settings->key_chat_close, evt.text.unicode);
}
