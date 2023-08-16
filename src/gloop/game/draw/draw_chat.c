/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** draw_chat
*/

#include "chat.h"

void draw_chat(sfRenderWindow *wd, chat_t *chat)
{
    sfRenderWindow_drawRectangleShape(wd, chat->backgound, NULL);
    sfRenderWindow_drawText(wd, chat->history_display, NULL);
    sfRenderWindow_drawText(wd, chat->input_display, NULL);
}
