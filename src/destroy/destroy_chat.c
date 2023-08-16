/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** destroy_chat
*/

#include "chat.h"
#include <stdlib.h>

void destroy_input(chat_input_t *chat)
{
    chat_input_t *tmp = NULL;

    while (chat->previous) {
        tmp = chat;
        chat = chat->previous;
        free(tmp);
    }
    free(chat);
}

static void destroy_history(chat_stack_t *chat)
{
    chat_stack_t *tmp = NULL;

    while (chat) {
        tmp = chat;
        chat = chat->previous;
        free(tmp->str);
        free(tmp);
    }
}

void destroy_chat(chat_t *chat)
{
    sfRectangleShape_destroy(chat->backgound);
    destroy_input(chat->input);
    destroy_history(chat->history);
    sfFont_destroy((sfFont *)sfText_getFont(chat->history_display));
    sfFont_destroy((sfFont *)sfText_getFont(chat->input_display));
    sfText_destroy(chat->history_display);
    sfText_destroy(chat->input_display);
    sfClock_destroy(chat->clock);
    free(chat);
}
