/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** create_player_id
*/

#include "tools.h"

int create_player_id(char *name)
{
    int hash = 0;

    for (int i = 0; i < my_strlen(name); i++)
        hash = 31 * hash + name[i];
    return hash;
}
