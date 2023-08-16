/*
** EPITECH PROJECT, 2023
** MMOPRG_ONLINE [SSH]
** File description:
** main
*/

#include "wnetcsfml.h"
#include "rpg_online_manager.h"
#include <time.h>

int main(void)
{
    srand(time(NULL));
    if (!w_netloop(10001, 1, &rpg_online_manager))
        return 84;
}
