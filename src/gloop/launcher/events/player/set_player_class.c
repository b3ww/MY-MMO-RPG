/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** set_player_class
*/

#include "rpg.h"

static void better_selector(player_t *player, sfKeyCode key_code)
{
    switch (key_code) {
    case sfKeyRight: player->skin.pclass++; player->skin.pclass %= 8; break;
    case sfKeyLeft:
        if (player->skin.pclass == 0)
            player->skin.pclass = 7;
        else
            player->skin.pclass--;
        player->skin.pclass %= 8;
        break;
    case sfKeyUp: player->skin.color++; player->skin.color %= 3; break;
    case sfKeyDown:
        if (player->skin.color == 0)
            player->skin.color = 2;
        else
            player->skin.color--;
        player->skin.color %= 3;
        break;
    default:
        break;
    }
}

void set_player_class(player_t *player, sfKeyCode key_code)
{
    better_selector(player, key_code);
    switch (key_code) {
    case sfKeyA: player->skin.color = BLUE; break;
    case sfKeyZ: player->skin.color = GREEN; break;
    case sfKeyE: player->skin.color = RED; break;
    case sfKeyQ: player->skin.pclass = ARCHER; break;
    case sfKeyS: player->skin.pclass = AXEFIGHTER; break;
    case sfKeyD: player->skin.pclass = AXEKNIGHT; break;
    case sfKeyF: player->skin.pclass = LANCEKNIGHT; break;
    case sfKeyG: player->skin.pclass = SPEARFIGHTER; break;
    case sfKeyH: player->skin.pclass = SWORDFIGHTER; break;
    case sfKeyJ: player->skin.pclass = THIEF; break;
    case sfKeyK: player->skin.pclass = WIZARD; break;
    case sfKeyRight: case sfKeyLeft: case sfKeyUp: case sfKeyDown: break;
    default:
        return;
    }
    reload_player_skin(player);
}
