/*
** EPITECH PROJECT, 2022
** keys
** File description:
** manage keys pressed
*/

#include "rpg.h"
#include "create.h"
#include "audio_manager.h"
#include "rpg_particles.h"
#include "tools.h"
#include "chat.h"
#include "tools.h"
#include "destroy.h"

void print_quest(rpg_t *rpg)
{
    add_to_chat(rpg->chat, "---");
    add_to_chat(rpg->chat, QUEST_NPC);
    add_to_chat(rpg->chat, QUEST_NPC1);
    add_to_chat(rpg->chat, QUEST_NPC2);
    add_to_chat(rpg->chat, QUEST_NPC3);
    add_to_chat(rpg->chat, "---");
}

static bool key_chat_n(rpg_t *rpg, char code)
{
    char *tmp_history = NULL;
    char *tmp_input;

    if (code == '\n' || sfKeyboard_isKeyPressed(sfKeyEnter)) {
        tmp_input = get_chat_input_content(rpg->chat->input);
        tmp_history = get_chat_history(rpg->chat->history);
        sfText_setString(rpg->chat->history_display, tmp_history);
        send_chat_message(rpg, tmp_input);
        !my_strcmp(tmp_input, " /quests") ? print_quest(rpg) : 0;
        free(tmp_history);
        free(tmp_input);
        destroy_input(rpg->chat->input);
        rpg->chat->input = malloc(sizeof(chat_input_t));
        rpg->chat->input->c = ' ';
        rpg->chat->input->previous = NULL;
        sfText_setString(rpg->chat->input_display,
        get_chat_input_content(rpg->chat->input));
        return false;
    }
    return true;
}

static void key_chat(rpg_t *rpg, char code)
{
    reset_chat_display(rpg->chat);
    if (!key_chat_n(rpg, code))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        rpg->chat->to_display = false;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyBackspace)) {
        rpg->chat->input = chat_input_delete_char(rpg->chat->input);
        sfText_setString(rpg->chat->input_display,
        get_chat_input_content(rpg->chat->input));
        return;
    }
    if (get_input_chat_size(rpg->chat->input) > 30)
        return;
    chat_input_add_letter(&rpg->chat->input, code);
    sfText_setString(rpg->chat->input_display,
    get_chat_input_content(rpg->chat->input));
}

void manage_keys_game(rpg_t *rpg, char code)
{
    if (rpg->chat->to_display) {
        key_chat(rpg, code);
        return;
    }
    if (rpg->settings->key_menu->actual == code ||
    sfKeyboard_isKeyPressed(sfKeyEscape))
        rpg->game->menu_in_game = !rpg->game->menu_in_game;
    if (rpg->settings->key_attack2->actual == code)
        anim_append(&rpg->anims, create_rain(get_anims_props(rpg->anims_props,
            RAIN_ANIM)));
    if (rpg->settings->key_inventory->actual == code) {
        rpg->game->inv->is_open = (rpg->game->inv->is_open) ? 0 : 1;
        end_smoke(rpg->anims);
    }
    if (rpg->settings->key_quest->actual == code)
        rpg->game->chest->is_open = (rpg->game->chest->is_open) ? 0 : 1;
    if (rpg->settings->key_chat_open->actual == code) {
        rpg->chat->to_display = !rpg->chat->to_display;
        sfClock_restart(rpg->chat->clock);
        reset_chat_display(rpg->chat);
    }
}
