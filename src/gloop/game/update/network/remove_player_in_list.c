/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** remove_player_in_list
*/

#include "rpg.h"
#include "disconnect.h"
#include "destroy.h"
#include "particle.h"
#include "fight.h"
#include "tools.h"

static void destroy_targeted_anims(anim_t **anims, player_t *player)
{
    anim_t *anim = *anims;
    anim_t *save_next = NULL;

    for (; anim != NULL; anim = save_next) {
        save_next = anim->next;
        if (anim->at_death != NULL && my_strcmp(((attack_data_t *)anim->
        at_death_data)->victim->name, player->name) == 0) {
            anim->duration = 0;
            destroy_particles(anim->particles);
            anim->particles = NULL;
            anim_destroy_secure(anims, anim);
        }
    }
}

static void destroy_anim_targeted(player_t *player, player_t *players[50],
uss_t player_count)
{
    for (int i = 0; i < player_count; i++)
        destroy_targeted_anims(&players[i]->anims, player);
}

bool remove_player_in_list(net_t *network, player_t *players[50],
uss_t *player_count)
{
    disconnect_player_t *to_disconnect = (disconnect_player_t *)network->rdata;
    int player_id;

    player_id = get_player_id(players, *player_count, to_disconnect->name);
    if (player_id == 0)
        return true;
    if (player_id == -1)
        return false;
    for (int i = 0; i < *player_count; i++) {
        if (players[i]->fight.target == players[player_id])
            players[i]->fight.target = NULL;
    }
    destroy_anim_targeted(players[player_id], players, *player_count);
    destroy_player(players[player_id]);
    for (int j = player_id; j < *player_count; j++)
        players[j] = players[j + 1];
    (*player_count)--;
    return false;
}
