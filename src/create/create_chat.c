/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** create_chat
*/

#include "chat.h"
#include "rpg.h"
#include "tools.h"

static void stack_chat(chat_t *ret)
{
    ret->input_display = sfText_create();
    ret->input = malloc(sizeof(chat_input_t));
    ret->input->c = ' ';
    ret->history = NULL;
    ret->input->previous = NULL;
}

void chat_input_add_letter(chat_input_t **chat, char to_add)
{
    chat_input_t *new = malloc(sizeof(chat_input_t));

    new->c = to_add;
    new->previous = *chat;
    *chat = new;
}

void chat_history_add(chat_stack_t **chat, char *to_add)
{
    chat_stack_t *new = malloc(sizeof(chat_stack_t));

    new->str = my_strdup(to_add);
    new->previous = *chat;
    *chat = new;
}

char *get_chat_input_content(chat_input_t *chat)
{
    char *ret = NULL;
    char tmp[1024];
    int i = 0;

    for (; i < 1024 && chat; i++) {
        tmp[i] = chat->c;
        chat = chat->previous;
    }
    ret = malloc(sizeof(char) * (i + 1));
    ret[i--] = 0;
    for (int j = 0; i >= 0; i--, j++)
        ret[j] = tmp[i];
    return ret;
}

void *create_chat(void)
{
    chat_t *ret = malloc(sizeof(chat_t));

    ret->backgound = sfRectangleShape_create();
    sfRectangleShape_setFillColor(ret->backgound, sfColor_fromRGBA(0, 0, 0,
    150));
    sfRectangleShape_setSize(ret->backgound, (v2f_t){925, 400});
    sfRectangleShape_setPosition(ret->backgound, (v2f_t){0, 650});
    ret->history_display = sfText_create();
    sfText_setString(ret->history_display, "\n\n\n\n\n\n\n");
    sfText_setFont(ret->history_display, sfFont_createFromFile(FONT));
    sfText_setScale(ret->history_display, (v2f_t){1, 1.73});
    sfText_setPosition(ret->history_display, (v2f_t){0, 650});
    stack_chat(ret);
    sfText_setString(ret->input_display, "");
    sfText_setFont(ret->input_display, sfFont_createFromFile(FONT));
    sfText_setScale(ret->input_display, (v2f_t){1, 1.73});
    sfText_setPosition(ret->input_display, (v2f_t){0, 995});
    ret->to_display = sfFalse;
    ret->clock = sfClock_create();
    return ret;
}
