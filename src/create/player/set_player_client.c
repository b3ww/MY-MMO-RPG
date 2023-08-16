/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** set_player_client
*/

#include "player.h"
#include <stdlib.h>
#include "tools.h"
#include "create.h"

static void set_stats(player_t *player, player_server_t *player_server,
int player_found, sfFont *font)
{
    player->id = player_server->id;
    if (!player_found) {
        my_strcpy(player->name, player_server->name);
        player->stats.draw_name = create_draw_text(player->name, font);
        player->stats.health_bar = create_health_bar();
    }
    player->stats.max_health = player_server->max_health;
    player->stats.health = player_server->health;
    player->stats.previous_health = player_server->health;
    player->stats.regen = player_server->regen;
    player->stats.max_mana = player_server->max_mana;
    player->stats.mana = player_server->mana;
    player->stats.level = player_server->level;
    player->stats.exp = player_server->exp;
}

static void set_move(player_t *player, player_server_t *player_server,
int player_found)
{
    player->move.pos = player_server->pos;
    player->move.velocity = player_server->velocity;
    player->move.speed = player_server->speed;
    player->move.destination = player_server->destination;
    player->move.direction = RIGHT;
    sfSprite_setPosition(player->skin.sprite, player->move.pos);
    if (!player_found) {
        player->move.chest = NULL;
    }
}

static void set_kill_count_text(player_t *player)
{
    char *new_kills_str = my_strnbr(player->fight.kill_count);

    my_strcpy(player->fight.kills_str, new_kills_str);
    sfText_setString(player->fight.draw_kills, player->fight.kills_str);
    free(new_kills_str);
}

static void set_fight(player_t *player, player_server_t *player_server,
int player_found, sfFont *font)
{
    player->fight.range_type = player_server->range_type;
    player->fight.range = player_server->range;
    player->fight.attack_damage = player_server->attack_damage;
    player->fight.attack_speed = player_server->attack_speed;
    player->fight.projectile_speed = player_server->projectile_speed;
    player->fight.kill_count = player_server->kill_count;
    if (!player_found) {
        player->fight.attack_clock = sfClock_create();
        player->fight.regen_clock = sfClock_create();
        player->fight.target = NULL;
        my_strcpy(player->fight.hited_by, NOBODY);
        player->fight.kills_str = malloc(sizeof(10));
        player->fight.kills_str[0] = '\0';
        player->fight.draw_kills = create_draw_text("0", font);
        sfText_setColor(player->fight.draw_kills,
            sfColor_fromRGB(168, 238, 57));
        sfText_setOutlineThickness(player->fight.draw_kills, 2);
    }
    set_kill_count_text(player);
}

player_t *set_player_client(player_t *player, player_server_t *player_server,
int player_found, sfFont *font)
{
    set_stats(player, player_server, player_found, font);
    set_skin(player, player_server, player_found);
    set_move(player, player_server, player_found);
    set_fight(player, player_server, player_found, font);
    if (!player_found) {
        player->anims = NULL;
        player->portal = NULL;
    }
    sfRectangleShape_setPosition(player->skin.hitbox, player->move.pos);
    set_player_direction(player);
    return player;
}
