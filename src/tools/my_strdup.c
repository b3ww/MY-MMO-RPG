/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** Allow place in the memory
*/

#include <stdlib.h>
#include "tools.h"

char *my_strdup(char const *src)
{
    int size = my_strlen(src);
    char *str = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++)
        str[i] = src[i];
    str[size] = '\0';
    return str;
}
