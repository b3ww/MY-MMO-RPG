/*
** EPITECH PROJECT, 2022
** mdata_base
** File description:
** wstr_to_word_array
*/

#include "rpg_online_manager.h"

static bool is_in(char *sample, char c)
{
    for (int i = 0; sample[i]; i++) {
        if (c == sample[i])
            return true;
    }
    return false;
}

static char **prepare(char *str, char *sample)
{
    int size = 0;
    int len = wstrlen(str);
    char **ret;

    for (int i = 0; i < len; i++) {
        while (str[i] && is_in(sample, str[i]))
            i++;
        if (!str[i])
            break;
        size++;
        while (str[i] && !is_in(sample, str[i]))
            i++;
    }
    ret = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size + 1; i++)
        ret[i] = (void *)1;
    ret[size] = NULL;
    return ret;
}

static char *copy_to(char *src, char *sample)
{
    char *ret = NULL;
    int size = 0;

    while (src[size] && !is_in(sample, src[size]))
        size++;
    ret = malloc(sizeof(char) * (size + 1));
    ret[size] = 0;
    for (int i = 0; i < size; i++)
        ret[i] = src[i];
    return ret;
}

char **wstr_to_word_array(char *str, char *sample)
{
    int index = 0;
    int len = wstrlen(str);
    char **ret = prepare(str, sample);

    for (int i = 0; i < len && ret[index]; i++) {
        while (str[i] && is_in(sample, str[i]))
            i++;
        ret[index++] = copy_to(str + i, sample);
        while (str[i] && !is_in(sample, str[i]))
            i++;
        if (str[i])
            str[i] = '\0';
    }
    return ret;
}
