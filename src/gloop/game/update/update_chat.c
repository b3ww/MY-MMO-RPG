/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** update_chat
*/

#include "chat.h"
#include <stdlib.h>
#include "tools.h"
#include <stdio.h>
#include "wcsv.h"

chat_input_t *chat_input_delete_char(chat_input_t *chat)
{
    chat_input_t *tmp;
    if (chat->previous) {
        tmp = chat->previous;
        free(chat);
        return tmp;
    }
    return chat;
}

int get_input_chat_size(chat_input_t *chat)
{
    int ret = 0;

    while (chat) {
        chat = chat->previous;
        ret++;
    }
    return ret;
}

char *concat_strings(char **strings)
{
    char *result = malloc(7 * 80 + 1);

    memset(result, 0, 7 * 80 + 1);
    for (int i = 0; i < 7; i++) {
        strcat(result, strings[i]);
        strcat(result, "\n");
    }
    return result;
}

char *get_chat_history(chat_stack_t *stack)
{
    char **result = malloc(7 * sizeof(char *));

    for (int i = 0; i < 7; i++)
        result[i] = NULL;
    int i = 0;
    chat_stack_t *current = stack;
    while (current && i < 7) {
        result[i] = current->str;
        current = current->previous;
        i++;
    }
    for (; i < 7; i++)
        result[i] = "";
    for (int j = 0; j < 7 / 2; j++) {
        char *temp = result[j];
        result[j] = result[6 - j];
        result[6 - j] = temp;
    }
    return concat_strings(result);
}
