/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski [SSH: 193.70.40.62]
** File description:
** str_tools
*/

#include <stdbool.h>
#include <stdlib.h>

void wstrcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int wstrlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

int wstrcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        i++;
    }
    if (s1[i] > s2[i])
        return 1;
    if (s1[i] < s2[i])
        return -1;
    i++;
    return 0;
}

char *my_strdup(char const *src)
{
    int size = wstrlen((char *)src);
    char *str = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++)
        str[i] = src[i];
    str[size] = '\0';
    return str;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        i++;
    }
    if (s1[i] > s2[i])
        return 1;
    if (s1[i] < s2[i])
        return -1;
    i++;
    return 0;
}
