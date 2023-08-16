/*
** EPITECH PROJECT, 2023
** src/gloop/launcher/update/update_arrows
** File description:
** updates for arrow button
*/

#include "rpg.h"
#include "tools.h"

static int valid(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ':')
            return 1;
    }
    return 0;
}

void update_network_infos(rpg_t *rpg, char *ip_port)
{
    if (!valid(ip_port))
        return;
    char **infos = wstr_to_word_array(ip_port, ":");
    rpg->server_ip_address = sfIpAddress_fromString(infos[0]);
    rpg->server_port = my_getnbr(infos[1]);
    for (int i = 0; infos[i]; i++)
        free(infos[i]);
    free(infos);
}

void update_right_button_launcher(rpg_t *rpg, scene_launcher_t *launcher)
{
    switch (launcher->bt_right->state) {
        case HOVER: sfSprite_setTextureRect(launcher->bt_right->sprite,
                (sfIntRect){30, 0, ARROW_BUTTON_RECT}); break;
        case PRESSED: sfSprite_setTextureRect(launcher->bt_right->sprite,
                (sfIntRect){28, 0, ARROW_BUTTON_RECT}); break;
        case RELEASED: sfSprite_setTextureRect(launcher->bt_right->sprite,
                (sfIntRect){0, 0, ARROW_BUTTON_RECT});
            launcher->bt_right->state = HOVER;
            set_player_class(rpg->players[0], sfKeyRight);
            break;
        default: sfSprite_setTextureRect(launcher->bt_right->sprite,
            (sfIntRect){0, 0, ARROW_BUTTON_RECT}); break;
    }
}

void update_left_button_launcher(rpg_t *rpg, scene_launcher_t *launcher)
{
    switch (launcher->bt_left->state) {
        case HOVER: sfSprite_setTextureRect(launcher->bt_left->sprite,
            (sfIntRect){30, 0, ARROW_BUTTON_RECT});
            sfSprite_setPosition(launcher->bt_left->sprite,
                (v2f_t){17, 880}); break;
        case PRESSED: sfSprite_setTextureRect(launcher->bt_left->sprite,
                (sfIntRect){30, 0, ARROW_BUTTON_RECT});
            sfSprite_setPosition(launcher->bt_left->sprite,
                (v2f_t){5, 880}); break;
        case RELEASED: sfSprite_setTextureRect(launcher->bt_left->sprite,
                (sfIntRect){0, 0, ARROW_BUTTON_RECT});
            set_player_class(rpg->players[0], sfKeyLeft);
            launcher->bt_left->state = HOVER; break;
        default: sfSprite_setTextureRect(launcher->bt_left->sprite,
            (sfIntRect){0, 0, ARROW_BUTTON_RECT}); break;
    }
}
