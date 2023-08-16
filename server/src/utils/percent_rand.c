/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski [SSH: 193.70.40.62]
** File description:
** percent_rand
*/

#include <stdlib.h>
#include <stdbool.h>

bool percent(int value)
{
    if (value > 100)
        return false;
    if ((rand() % 100) < value)
        return true;
    return false;
}
