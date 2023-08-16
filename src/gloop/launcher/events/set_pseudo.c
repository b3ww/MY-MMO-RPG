/*
** EPITECH PROJECT, 2023
** src/gloop/launcher/evts/set_pseudo
** File description:
** set pseudo
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "tools.h"
#include <stdlib.h>

static void my_str_moove(char *str, int is_right)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] == '|')
            break;

    if (is_right == 1) {
        str[i] = str[i + 1];
        str[i + 1] = '|';
    } else {
        str[i] = str[i - 1];
        str[i - 1] = '|';
    }
}

int is_containing_char(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

void delete_char(char *str, int mode)
{
    char *cpy = malloc(sizeof(char) * 30);
    int i = 0;

    cpy = my_strcpy(cpy, str);
    for (; str[i] != '\0'; i++)
        if (str[i] == '|')
            break;
    if (!mode) {
        if (str[i] == '\0') {
            free(cpy);
            return;
        }
        i++;
    }
    for (; cpy[i] != '\0'; i++)
        str[i - 1] = cpy[i];
    str[i - 1] = '\0';
    free(cpy);
}

void set_text_move(char *pseudo_str, sfText *pseudo)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
    pseudo_str[0] != '|')
        my_str_moove(pseudo_str, 0);
    if (sfKeyboard_isKeyPressed(sfKeyRight) &&
    pseudo_str[my_strlen(pseudo_str) - 1] != '|') {
        my_str_moove(pseudo_str, 1);
    }
    sfText_setString(pseudo, pseudo_str);
}

void set_pseudo(char *pseudo_str, sfText *pseudo, sfEvent evt, int size)
{
    int place = 0;
    char *temp;
    for (; pseudo_str[place] != '|'; place++);
    if (sfKeyboard_isKeyPressed(sfKeyBackspace) && pseudo_str[0] != '|') {
        delete_char(pseudo_str, 1);
        sfText_setString(pseudo, pseudo_str);
        return;
    }
    temp = malloc(sizeof(char) * size);
    my_strcpy(temp, pseudo_str);
    if (evt.text.unicode >= 32 && evt.text.unicode <= 126 &&
    evt.text.unicode != 124 && my_strlen(pseudo_str) < size - 1) {
        pseudo_str[place] = (char)evt.text.unicode;
        pseudo_str[place + 1] = '|';
        for (place++; temp[place]; place++)
            pseudo_str[place + 1] = temp[place];
        pseudo_str[place + 1] = '\0';
    }
    sfText_setString(pseudo, pseudo_str);
    free(temp);
}
