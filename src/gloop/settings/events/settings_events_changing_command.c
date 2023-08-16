/*
** EPITECH PROJECT, 2023
** src/gloop/settings/events/settings_events_changing_command
** File description:
** changing button action
*/

#include "rpg.h"

static void is_settings_released(keys_changer_t *key, sfMouseButtonEvent evt)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(key->rect);

    if (sfFloatRect_contains(&bound, evt.x, evt.y) == sfTrue) {
        key->is_clicked = sfTrue;
        sfText_setColor(key->text->text, sfWhite);
    } else {
        key->is_clicked = sfFalse;
        sfText_setColor(key->text->text, sfColor_fromRGBA(T_COLOR));
    }
}

void settings_button_hover(scene_settings_t *settings, sfMouseMoveEvent evt)
{
    settings->back->is_hover(settings->back, &evt);
    settings->cancel->is_hover(settings->cancel, &evt);
    settings->music->is_hover(settings->music, &evt);
    settings->sound->is_hover(settings->sound, &evt);
}

void settings_button_pressed(scene_settings_t *settings,
sfMouseButtonEvent evt)
{
    settings->back->is_pressed(settings->back, &evt);
    settings->music->is_pressed(settings->music, &evt);
    settings->sound->is_pressed(settings->sound, &evt);
    settings->cancel->is_pressed(settings->cancel, &evt);
}

void settings_button_released(scene_settings_t *set,
sfMouseButtonEvent evt)
{
    is_settings_released(set->key_attack1, evt);
    is_settings_released(set->key_attack2, evt);
    is_settings_released(set->key_attack3, evt);
    is_settings_released(set->key_attack4, evt);
    is_settings_released(set->key_menu, evt);
    is_settings_released(set->key_inventory, evt);
    is_settings_released(set->key_quest, evt);
    is_settings_released(set->key_chat_open, evt);
    is_settings_released(set->key_chat_close, evt);
    set->back->is_released(set->back, &evt);
    set->music->is_released(set->music, &evt);
    set->sound->is_released(set->sound, &evt);
    set->cancel->is_released(set->cancel, &evt);
}
