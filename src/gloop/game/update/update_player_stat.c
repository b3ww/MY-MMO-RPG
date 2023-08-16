/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** update_player_stat
*/

#include "tools.h"
#include "rpg.h"

void save_inventory(rpg_t *rpg)
{
    slot_t **slots = rpg->game->inv->slots;
    char **line = rpg->file_config.inv_save->content[1];

    for (int i = 0; i < 12; i++) {
        if (slots[i])
            line[i] = slots[i]->slots->unconso->name;
        else
            line[i] = my_strdup("none");
    }
    wcsv_apply(rpg->file_config.inv_save);
}

void update_player_stat(rpg_t *rpg)
{
    slot_t **slots = rpg->game->inv->slots;


    rpg->players[0]->fight.attack_damage = rpg->copy_player.attack_damage;
    rpg->players[0]->stats.health = rpg->copy_player.health;
    rpg->players[0]->move.speed = rpg->copy_player.speed;
    if (slots[3]) {
        rpg->players[0]->fight.attack_damage = rpg->copy_player.attack_damage +
        slots[3]->slots->unconso->attack;
    }
    if (slots[4]) {
        rpg->players[0]->stats.health = rpg->copy_player.health +
        slots[4]->slots->unconso->health;
    }
    if (slots[5]) {
        rpg->players[0]->move.speed = rpg->copy_player.speed +
        slots[5]->slots->unconso->speed;
    }
    send_player_connect_update(rpg->network, rpg->players[0], PLAYER_UPDATE,
    rpg->map->id);
}
