/*
** EPITECH PROJECT, 2022
** my_putstrerror
** File description:
** displays the characters of a string
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    write(1, str, len);
    return (0);
}
