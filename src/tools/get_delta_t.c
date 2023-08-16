/*
** EPITECH PROJECT, 2022
** get_delta_t
** File description:
** gets delta t
*/

#include "rpg.h"

void get_delta_t(rpg_t *rpg)
{
    sfInt64 now = sfClock_getElapsedTime(rpg->game_clock).microseconds;
    rpg->dt = (now - rpg->previous_frame) / 1000000.0 * GAME_TICK;
    rpg->previous_frame = now;
}
