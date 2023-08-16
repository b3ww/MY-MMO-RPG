/*
** EPITECH PROJECT, 2022
** get_delta_t
** File description:
** gets delta t
*/

#include "particle.h"

double get_delta_time(sfClock *game_clock, double *prev_frame_time)
{
    sfInt64 now = sfClock_getElapsedTime(game_clock).microseconds;
    double dt = (now - *prev_frame_time) / 1000000.0 * GAME_TICK;

    *prev_frame_time = now;
    return dt;
}
