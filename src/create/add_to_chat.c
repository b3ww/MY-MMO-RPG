/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** add_to_chat
*/

#include "chat.h"
#include "share.h"
#include "rpg_particles.h"
#include "network.h"
#include "item.h"
#include "inv_item_share.h"
#include "inventory.h"
#include "tools.h"
#include "create.h"
#include "rpg.h"

void reset_chat_display(chat_t *chat)
{
    sfColor ct = sfText_getFillColor(chat->history_display);
    sfClock_restart(chat->clock);
    sfRectangleShape_setFillColor(chat->backgound,
        sfColor_fromRGBA(0, 0, 0, 150));
    sfText_setColor(chat->history_display,
        sfColor_fromRGBA(ct.r, ct.g, ct.b, 255));
    sfText_setColor(chat->input_display,
        sfColor_fromRGBA(ct.r, ct.g, ct.b, 255));
}

void add_to_chat(chat_t *chat, char *str)
{
    char *tmp = NULL;
    chat_history_add(&chat->history, str);
    tmp = get_chat_history(chat->history);
    sfText_setString(chat->history_display, tmp);
    free(tmp);
    chat->to_display = true;
    reset_chat_display(chat);
}

void send_chat_message(rpg_t *rpg, char *message)
{
    chat_message_t to_send;

    my_strcpy(to_send.msg, message);
    my_strcpy(to_send.name, rpg->players[0]->name);
    to_send.type = MESSAGE_CHAT;
    send_to_server(rpg->network, &to_send);
    return;
}

void add_item_to_inventory(rpg_t *rpg, char *name)
{
    inventory_t *inv = rpg->game->inv;

    for (int i = 3; i < 12; i++) {
        if (!inv->slots[i]) {
            inv->slots[i] = create_item_manager(rpg, name);
            !inv->slots[i] ? add_to_chat(rpg->chat, "ERROR : GIVE") : 0;
            return;
        }
    }
}

void parse_chat_message(rpg_t *rpg, char *message)
{
    char **tmp = wstr_to_word_array(message, " \t");

    if (!tmp || !tmp[0])
        return;
    if (!strcmp(tmp[0], "/rain"))
        anim_append(&rpg->anims, create_rain(get_anims_props(rpg->anims_props,
            RAIN_ANIM)));
    if (!strcmp(tmp[0], "/kill") || !strcmp(tmp[0], "/KILL")) {
        if (!strcmp(tmp[1], rpg->players[0]->name)) {
            rpg->players[0]->stats.health = -42;
            my_strcpy(rpg->players[0]->fight.hited_by, NOBODY);
            send_death_signal(rpg->players[0], rpg->network);
        }
    }
    if (!strcmp(tmp[0], "/give")) {
        if (!tmp[1] || !tmp[2])
            return;
        if (!my_strcmp(tmp[1], "all") || !my_strcmp(tmp[1], "ALL") ||
        !my_strcmp(tmp[1], rpg->players[0]->name))
            add_item_to_inventory(rpg, tmp[2]);
    }
}
