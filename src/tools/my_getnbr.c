/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** return the first number found in a string
*/

#include <stdbool.h>

static bool my_char_isnum(char const c)
{
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

static int count_neg(char const *str, int *i)
{
    int minus_count = 0;

    while (str[*i] == '-' && str[*i] != '\0') {
        minus_count++;
        (*i)++;
    }
    return (minus_count % 2 == 1);
}

int my_getnbr(char const *str)
{
    long number = 0;
    int int_nb;
    int i = 0;
    int is_neg = count_neg(str, &i);

    if (!my_char_isnum(str[i]))
        return 0;
    for (; str[i] != '\0'; i++) {
        if (my_char_isnum(str[i])) {
            number *= 10;
            number += str[i] - 48;
        } else {
            break;
        }
        if (number > __INT_MAX__ || number < -__INT_MAX__)
            return 0;
    }
    (is_neg) ? number *= -1 : 0;
    int_nb = number;
    return int_nb;
}
