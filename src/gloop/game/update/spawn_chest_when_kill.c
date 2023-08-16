/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** spawn_chest_when_kill
*/

#include "rpg.h"
#include "die_share.h"
#include "tools.h"
#include "network.h"

static void upgrade_player(player_t *player)
{
    player->stats.max_health += 10;
    player->stats.health += 50;
    if (player->stats.health > player->stats.max_health)
        player->stats.health = player->stats.max_health;
    player->fight.attack_speed += 0.1;
    player->fight.attack_speed *= 1.1;
    player->fight.attack_damage += 5;
    player->stats.regen += 2;
    player->move.speed += 10;
}

void spawn_chest_when_kill(net_t *network, player_t *player,
scene_game_t *game, map_id_t map_id)
{
    player_die_t *die = ((player_die_t *)network->rdata);

    if (my_strcmp(player->name, die->killer) == 0) {
        game->l_chest = create_chest(game->l_chest, die->pos);
        player->fight.kill_count++;
        upgrade_player(player);
        send_player_connect_update(network, player, PLAYER_UPDATE, map_id);
    }
}
