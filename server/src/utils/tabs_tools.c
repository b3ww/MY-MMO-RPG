/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski [SSH: 193.70.40.62]
** File description:
** tabs_tools
*/

#include "wcsv.h"

char **wrtab_copy(char **tab)
{
    int size = TABSIZE(tab);
    char **tab_ret = malloc(sizeof(char *) * (size + 1));

    tab_ret[size] = NULL;
    for (int i = 0; tab[i]; i++) {
        tab_ret[i] = malloc(sizeof(char) * (TABSIZE(tab[i]) + 1));
        tab_ret[i][TABSIZE(tab[i])] = '\0';
        for (int j = 0; tab[i][j]; j++)
            tab_ret[i][j] = tab[i][j];
    }
    return tab_ret;
}

char *skip_ws(char *str)
{
    int size = 0;
    char *buffer_ret = NULL;
    int index = 0;

    for (int i = 0; str[i]; i++)
        size += ISWS(str[i]) ? 0 : 1;
    buffer_ret = malloc(sizeof(char) * (size + 1));
    buffer_ret[size] = '\0';
    for (int i = 0; str[i]; i++) {
        if (!ISWS(str[i])) {
            buffer_ret[index] = str[i];
            index++;
        }
    }
    return buffer_ret;
}
