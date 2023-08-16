/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** play_button_clicked
*/

#include "rpg.h"
#include "tools.h"
#include "audio_manager.h"
#include <stdlib.h>
#include "create.h"

void play_button_clicked(rpg_t *rpg)
{
    my_strcpy(rpg->player_name, rpg->launcher->pseudo->str);
    my_strcpy(rpg->players[0]->name, rpg->player_name);
    rpg->players[0]->id = create_player_id(rpg->player_name);
    sfText_setString(rpg->players[0]->stats.draw_name, rpg->player_name);
    play_music(rpg->audio_manager, "main");
    rpg->scene = GAME;
    sfSprite_setScale(rpg->players[0]->skin.sprite, (v2f_t){3, 3});
    // rpg->map = load_map(rpg, 0);
    // rpg->players[0]->move.pos = (v2f_t){290, 220};
    switch (rpg->players[0]->skin.color) {
    case RED: rpg->map = load_map(rpg, 0);
        rpg->players[0]->move.pos = (v2f_t){290, 220}; break;
    case GREEN: rpg->map = load_map(rpg, 2);
        rpg->players[0]->move.pos = (v2f_t){1635, 420}; break;
    case BLUE: rpg->map = load_map(rpg, 4);
        rpg->players[0]->move.pos = (v2f_t){200, 820}; break;
    default: break;
    }
    rpg->timeout_clock = sfClock_create();
}
