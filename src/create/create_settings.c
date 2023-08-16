/*
** EPITECH PROJECT, 2023
** src/create/create_settings_t
** File description:
** crete settings scene
*/

#include "button.h"
#include "scene_settings.h"
#include <stdlib.h>
#include "tools.h"

keys_changer_t *create_keys_changer(char const *str, v2f_t pos)
{
    keys_changer_t *ele = malloc(sizeof(keys_changer_t));

    ele->str = my_strdup(str);
    ele->base = str[my_strlen(str) - 1];
    ele->actual = str[my_strlen(str) - 1];
    ele->text = create_text(str, 0, 50, pos);
    sfText_setColor(ele->text->text, sfColor_fromRGBA(T_COLOR));
    sfText_setOutlineThickness(ele->text->text, 3);
    ele->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(ele->rect, (v2f_t){pos.x - 5, pos.y - 5});
    sfRectangleShape_setSize(ele->rect, (v2f_t){450, 60});
    sfRectangleShape_setFillColor(ele->rect, sfColor_fromRGBA(T_COLOR));
    return ele;
}

void create_settings_button(scene_settings_t *settings)
{
    settings->back = create_button(ASSET_BUTTON, (v2f_t){815, 950},
        (v2f_t){3.75, 3.75},
        &((sfIntRect){BACK_BUTTON_LINE_POS, SIZE_BUTTON_LINE}));
    settings->music = create_button(ASSET_FREE_LAUNCH,
        (v2f_t){1800, 300}, (v2f_t){3.75, 3.75},
        &((sfIntRect){MUSIC_BUTTON_LINE_POS, MUSIC_SOUND_ASSET_SIZE}));
    settings->sound = create_button(ASSET_FREE_LAUNCH,
        (v2f_t){1725, 300}, (v2f_t){3.75, 3.75},
        &((sfIntRect){SOUND_BUTTON_LINE_POS, MUSIC_SOUND_ASSET_SIZE}));
    settings->cancel = create_button(ASSET_BUTTON, (v2f_t){750, 500},
        (v2f_t){3, 3},
        &((sfIntRect){CANCEL_BUTTON_LINE_POS, SIZE_BUTTON_LINE}));
}

static void key_settings_create(scene_settings_t *set)
{
    set->key_attack1 = create_keys_changer("Attack 1 : a", (v2f_t){75, 300});
    set->key_attack2 = create_keys_changer("Attack 2 : z", (v2f_t){75, 400});
    set->key_attack3 = create_keys_changer("Attack 3 : e", (v2f_t){75, 500});
    set->key_attack4 = create_keys_changer("Attack 4 : r", (v2f_t){75, 600});
    set->key_inventory = create_keys_changer("Inventory : i",
        (v2f_t){75, 700});
    set->key_menu = create_keys_changer("Menu : esc. or p", (v2f_t){75, 800});
    set->key_quest = create_keys_changer("Quest : q", (v2f_t){75, 900});
    set->key_chat_open = create_keys_changer("Open chat : t",
        (v2f_t){600, 300});
    set->key_chat_close = create_keys_changer("Close chat : esc. or `",
        (v2f_t){600, 400});
}

scene_settings_t *create_settings(void)
{
    scene_settings_t *settings = malloc(sizeof(scene_settings_t));

    key_settings_create(settings);
    settings->title = create_text("SETTINGS", 0, 175, (v2f_t){TITLE_PO});
    settings->title_command = create_text("COMMAND", 0, 70,
        (v2f_t){330, 220});
    create_settings_button(settings);
    return settings;
}
