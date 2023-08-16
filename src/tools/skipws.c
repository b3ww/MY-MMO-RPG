/*
** EPITECH PROJECT, 2023
** csv_parser
** File description:
** skipws
*/

#include "wcsv.h"

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
