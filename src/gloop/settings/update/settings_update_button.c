/*
** EPITECH PROJECT, 2023
** src/gloop/settings/update/settings_update_button
** File description:
** update button for settings
*/

#include "rpg.h"
#include "scene_settings.h"

void settings_music_button(rpg_t *rpg)
{
    switch (rpg->settings->music->state) {
        case HOVER: sfSprite_setTextureRect(rpg->settings->music->sprite,
            (sfIntRect){((rpg->settings->is_music) ? 1 : 2) * JUMP_MUSIC_SOUND,
                0, SIZE_MUSIC_SOUND_BUTTON}); break;
        case PRESSED: sfSprite_setTextureRect(rpg->settings->music->sprite,
                (sfIntRect){0, 0, SIZE_MUSIC_SOUND_BUTTON}); break;
        case RELEASED: sfSprite_setTextureRect(rpg->settings->music->sprite,
                (sfIntRect){((rpg->settings->is_music) ? 0 : 0) *
                JUMP_MUSIC_SOUND, 0, SIZE_MUSIC_SOUND_BUTTON});
            rpg->settings->music->state = HOVER;
            if (rpg->settings->is_music == sfTrue)
                rpg->settings->is_music = sfFalse;
            else
                rpg->settings->is_music = sfTrue;
            break;
        default: sfSprite_setTextureRect(rpg->settings->music->sprite,
            (sfIntRect){((rpg->settings->is_music) ? 0 : 2) * JUMP_MUSIC_SOUND,
            0, SIZE_MUSIC_SOUND_BUTTON}); break;
    }
}

void settings_sound_button(rpg_t *rpg)
{
    switch (rpg->settings->sound->state) {
        case HOVER: sfSprite_setTextureRect(rpg->settings->sound->sprite,
            (sfIntRect){((rpg->settings->is_sound) ? 1 : 2) * JUMP_MUSIC_SOUND,
                0, SIZE_MUSIC_SOUND_BUTTON}); break;
        case PRESSED: sfSprite_setTextureRect(rpg->settings->sound->sprite,
                (sfIntRect){((rpg->settings->is_sound) ? 2 : 0) *
                JUMP_MUSIC_SOUND, 0, SIZE_MUSIC_SOUND_BUTTON}); break;
        case RELEASED: sfSprite_setTextureRect(rpg->settings->sound->sprite,
                (sfIntRect){0, 0, SIZE_MUSIC_SOUND_BUTTON});
            rpg->settings->sound->state = HOVER;
            if (rpg->settings->is_sound == sfTrue)
                rpg->settings->is_sound = sfFalse;
            else
                rpg->settings->is_sound = sfTrue;
            break;
        default: sfSprite_setTextureRect(rpg->settings->sound->sprite,
            (sfIntRect){((rpg->settings->is_sound) ? 0 : 2) * JUMP_MUSIC_SOUND,
            0, SIZE_MUSIC_SOUND_BUTTON}); break;
    }
}

static void cancel_fct(scene_settings_t *settings)
{
    change_letter(settings->key_attack1, settings->key_attack1->base);
    change_letter(settings->key_attack2, settings->key_attack2->base);
    change_letter(settings->key_attack3, settings->key_attack3->base);
    change_letter(settings->key_attack4, settings->key_attack4->base);
    change_letter(settings->key_inventory, settings->key_inventory->base);
    change_letter(settings->key_menu, settings->key_menu->base);
    change_letter(settings->key_quest, settings->key_quest->base);
    change_letter(settings->key_chat_open, settings->key_chat_open->base);
    change_letter(settings->key_chat_close, settings->key_chat_close->base);
}

void settings_cancel_button(rpg_t *rpg)
{
    switch (rpg->settings->cancel->state) {
        case HOVER: sfSprite_setTextureRect(rpg->settings->cancel->sprite,
                (sfIntRect){BUTTON_JUMP, 0, SIZE_CANCEL_BUTTON}); break;
        case PRESSED: sfSprite_setTextureRect(rpg->settings->cancel->sprite,
                (sfIntRect){2 * BUTTON_JUMP, 0, SIZE_CANCEL_BUTTON}); break;
        case RELEASED: sfSprite_setTextureRect(rpg->settings->cancel->sprite,
                (sfIntRect){BUTTON_JUMP, 0, SIZE_CANCEL_BUTTON});
            rpg->settings->cancel->state = HOVER;
            cancel_fct(rpg->settings);
            break;
        default: sfSprite_setTextureRect(rpg->settings->cancel->sprite,
            (sfIntRect){0, 0, SIZE_CANCEL_BUTTON}); break;
    }
}

void settings_back_button(rpg_t *rpg)
{
    switch (rpg->settings->back->state) {
        case HOVER: sfSprite_setTextureRect(rpg->settings->back->sprite,
                (sfIntRect){BUTTON_JUMP, 0, SIZE_BACK_BUTTON}); break;
        case PRESSED: sfSprite_setTextureRect(rpg->settings->back->sprite,
                (sfIntRect){2 * BUTTON_JUMP, 0, SIZE_BACK_BUTTON}); break;
        case RELEASED:
            rpg->settings->back->state = HOVER;
            rpg->scene = rpg->settings->scene_before;
            break;
        default: sfSprite_setTextureRect(rpg->settings->back->sprite,
            (sfIntRect){0, 0, SIZE_BACK_BUTTON}); break;
    }
}
