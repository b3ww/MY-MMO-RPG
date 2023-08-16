/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** create_player_me
*/

#include "struct.h"
#include "create.h"
#include "tools.h"
#include <stdlib.h>
#include "tools.h"

static void fill_me(player_server_t *me)
{
    me->health = me->max_health;
    me->mana = me->max_mana;
    me->destination = me->pos;
    me->color = RED;
    me->anim_state = IDLE_STATE;
    me->pos = (v2f_t){230, 850};
    me->velocity = (v2f_t){0, 0};
    me->level = 1;
    me->exp = 0;
    me->kill_count = 0;
}

static player_server_t *create_me_server(pname_t player_name,
wcsv_t *pcsv)
{
    player_server_t *me = malloc(sizeof(player_server_t));
    char *class = "archer";

    me->type = PLAYER_CONNECTION;
    me->player_class = ARCHER;
    my_strcpy(me->name, player_name);
    me->id = create_player_id(player_name);
    me->max_health = get_csv_value(pcsv, class, "max_health");
    me->regen = get_csv_value(pcsv, class, "regen");
    me->max_mana = get_csv_value(pcsv, class, "max_mana");
    me->speed = get_csv_value(pcsv, class, "movement_speed");
    me->range_type = get_csv_value(pcsv, class, "range_type");
    me->range = get_csv_value(pcsv, class, "range");
    me->attack_damage = get_csv_value(pcsv, class, "attack_damage");
    me->attack_speed = (float)get_csv_value(pcsv, class, "attack_speed") / 100;
    me->projectile_speed = get_csv_value(pcsv, class, "projectile_speed");
    fill_me(me);
    return me;
}

player_t *create_player_me(sfFont *font, pname_t player_name,
wcsv_t *pcsv)
{
    player_t *player = malloc(sizeof(player_t));
    player_server_t *me = create_me_server(player_name, pcsv);

    set_player_client(player, me, 0, font);
    free(me);
    return player;
}
