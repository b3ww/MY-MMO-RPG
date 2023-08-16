/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** get_with_value
*/

#include "wcsv.h"
#include "tools.h"

char **get_line_with_value(wcsv_t *parse, char *value)
{
    char **ret = NULL;

    for (int i = 0; parse->content[i]; i++) {
        for (int j = 0; parse->content[i][j]; j++)
            !my_strcmp(parse->content[i][j], value) ?
            ret = parse->content[i] : 0;
    }
    return ret;
}

char **get_column_with_value(wcsv_t *parse, char *value)
{
    int index = 0;
    char **ret = NULL;
    int size = TABSIZE(parse->content);

    for (int i = 0; parse->content[i]; i++) {
        for (int j = 0; parse->content[i][j]; j++)
            !my_strcmp(parse->content[i][j], value) ? index = j : 0;
    }
    ret = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++)
        ret[i] = parse->content[i][index];
    return ret;
}
