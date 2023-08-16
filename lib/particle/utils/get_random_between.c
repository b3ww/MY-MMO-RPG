/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** get_random_between
*/

#include <stdlib.h>

int get_random_nb_between(int from, int min, int max, int epsilon)
{
    from += rand() % (2 * epsilon) - epsilon;
    if (from < min)
        from = min;
    if (from > max)
        from = max;
    return from;
}
