/*
** EPITECH PROJECT, 2023
** src/create/create_text
** File description:
** create text
*/

#include "text.h"
#include <stdlib.h>
#include "string.h"

text_t *create_text(char const *str, int max_len, unsigned int character_size,
v2f_t pos)
{
    text_t *text = malloc(sizeof(text_t));

    text->text = sfText_create();
    text->font = sfFont_createFromFile(FONT);
    if (max_len != 0) {
        text->str = malloc(sizeof(char) * max_len + 1);
        text->str[max_len] = '\0';
        text->str[0] = '\0';
        strcpy(text->str, str);
        text->max_length = max_len;
    } else {
        text->max_length = -1;
        text->str = NULL;
    }
    sfText_setString(text->text, str);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, character_size);
    sfText_setColor(text->text, sfWhite);
    sfText_move(text->text, pos);
    return text;
}
