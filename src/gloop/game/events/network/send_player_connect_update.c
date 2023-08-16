/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** send_player_connect_update
*/

#include "rpg.h"
#include "tools.h"

static void fill_stats(player_server_t *me, player_t *player)
{
    me->max_health = player->stats.max_health;
    me->health = player->stats.health;
    me->max_mana = player->stats.max_mana;
    me->regen = player->stats.regen;
    me->mana = player->stats.mana;
    me->speed = player->move.speed;
}

static void fill_fight(player_server_t *me, player_t *player)
{
    me->range_type = player->fight.range_type;
    me->range = player->fight.range;
    me->attack_damage = player->fight.attack_damage;
    me->attack_speed = player->fight.attack_speed;
    me->projectile_speed = player->fight.projectile_speed;
    me->kill_count = player->fight.kill_count;
}

void send_player_connect_update(net_t *net, player_t *player, data_type_t type,
map_id_t id)
{
    player_server_t me;

    me.type = type;
    me.id = player->id;
    my_strcpy(me.name, player->name);
    fill_stats(&me, player);
    me.player_class = player->skin.pclass;
    me.color = player->skin.color;
    me.anim_state = player->skin.anim_state;
    me.pos = player->move.pos;
    me.velocity = player->move.velocity;
    me.destination = player->move.destination;
    fill_fight(&me, player);
    me.map = id;
    send_to_server(net, &me);
}
