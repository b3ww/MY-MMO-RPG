/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** shortcut
*/

#pragma once

    #include <SFML/Graphics.h>
    #include <stdbool.h>

    typedef unsigned short uss_t;
    typedef sfVector2f v2f_t;
    typedef sfVector2i v2i_t;
    typedef char pname_t[20];

    #define GET_CLOCK_SEC(clock) sfClock_getElapsedTime(clock).microseconds \
/ 1000000.0
