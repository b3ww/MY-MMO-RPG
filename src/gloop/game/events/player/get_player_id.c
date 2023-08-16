/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** get_player_id
*/

#include "player.h"
#include "tools.h"

int get_player_id(player_t *players[50], uss_t player_count, pname_t name)
{
    for (int i = 0; i < player_count; i++) {
        if (my_strcmp(players[i]->name, name) == 0)
            return i;
    }
    return -1;
}
