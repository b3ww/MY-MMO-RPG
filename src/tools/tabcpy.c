/*
** EPITECH PROJECT, 2023
** csv_parser
** File description:
** tabcpy
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
