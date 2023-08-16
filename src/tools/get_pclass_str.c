/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** get_pclass_str
*/

#include "player_class.h"
#include <stdlib.h>

char *get_pclass_str(player_class_t pclass)
{
    switch (pclass) {
    case ARCHER: return "archer";
    case AXEFIGHTER: return "axefighter";
    case AXEKNIGHT: return "axeknight";
    case LANCEKNIGHT: return "lanceknight";
    case SPEARFIGHTER: return "spearfighter";
    case SWORDFIGHTER: return "swordfighter";
    case THIEF: return "thief";
    case WIZARD: return "wizard";
    default: return NULL;
    }
}
