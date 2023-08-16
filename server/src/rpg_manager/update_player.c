/*
** EPITECH PROJECT, 2023
** MMOPRG_ONLINE [SSH: 193.70.40.62]
** File description:
** update_player
*/

#include "player_share.h"
#include "move_share.h"
#include "wnetcsfml.h"
#include "rpg_online_manager.h"

static void fill_dest_fight(player_server_t *dest, player_server_t *src)
{
    dest->range_type = src->range_type;
    dest->range = src->range;
    dest->attack_speed = src->attack_speed;
    dest->attack_damage = src->attack_damage;
    dest->projectile_speed = src->projectile_speed;
    dest->kill_count = src->kill_count;
}

void update_player(player_server_t *dest, player_server_t *src)
{
    dest->anim_state = src->anim_state;
    dest->color = src->color;
    dest->destination = src->destination;
    dest->max_health = src->max_health;
    dest->health = src->health;
    dest->mana = src->mana;
    dest->max_mana = src->max_mana;
    dest->regen = src->regen;
    dest->level = src->level;
    dest->exp = src->exp;
    dest->id = src->id;
    dest->map = src->map;
    dest->kill_count = src->kill_count;
    for (int i = 0; i < 20; i++)
        dest->name[i] = src->name[i];
    dest->player_class = src->player_class;
    dest->pos = src->pos;
    dest->type = src->type;
    dest->velocity = src->velocity;
    dest->speed = src->speed; fill_dest_fight(dest, src);
}

void update_player_move(player_server_t *dest, move_player_t *src)
{
    dest->anim_state = src->anim_state;
    dest->pos = src->destination;
    dest->map = src->map;
    dest->speed = src->speed;
    dest->destination = src->destination;
}
