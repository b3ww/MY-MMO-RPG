/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** get_color
*/

#include "shortcut.h"
#include "player.h"

sfColor get_color(player_color_t enum_color)
{
    switch (enum_color) {
    case RED:
        return sfRed;
    case BLUE:
        return sfBlue;
    case GREEN:
        return sfGreen;
    default:
        return sfTransparent;
    }
}
