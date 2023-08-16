/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** attack_in_range
*/

#include "rpg_player_anims.h"
#include <stdlib.h>
#include "tools.h"
#include "fight.h"

static void send_attack_anim(player_t *player, anim_props_t *anims_props)
{
    attack_data_t *attack;

    attack = malloc(sizeof(attack_data_t));
    attack->attacker = player;
    attack->victim = player->fight.target;
    anim_append(&player->anims, create_arrow_anim(get_anims_props(
        anims_props, ARROW_ANIM), attack));
}

static void attack_in_range(player_t *player, anim_props_t *anims_props)
{
    if (player->skin.anim_state == ATTACK_STATE && player->fight.range_type
    == RANGE)
        return;
    if (GET_CLOCK_SEC(player->fight.attack_clock) < 1 /
    player->fight.attack_speed) {
        if (get_distance(player->move.pos, player->fight.target->move.pos)
        <= player->fight.range - 20 && player->skin.anim_state ==
        MOVEMENT_STATE)
            player->skin.anim_state = IDLE_STATE;
        return;
    }
    if (player->fight.range_type == MELEE)
        player_send_attack(player, player->fight.target);
    player->skin.anim_state = ATTACK_STATE;
    player->skin.anim_rect.left = 32;
    sfClock_restart(player->fight.attack_clock);
    if (player->fight.range_type == RANGE)
        send_attack_anim(player, anims_props);
}

static void remove_arrow_anim(anim_t *anims)
{
    anim_t *anim = anims;

    for (; anim != NULL; anim = anim->next) {
        if (anim->id == ARROW_ANIM)
            anim->duration = 0;
    }
}

void attack_or_move(player_t *player, double dt, anim_props_t *anims_props,
bool **hitboxes)
{
    if (player->stats.health <= 0) {
        player->skin.anim_state = DEATH_STATE;
        return;
    }
    if (player->fight.target != NULL) {
        if (get_distance(player->move.pos, player->fight.target->move.pos)
        <= player->fight.range) {
            attack_in_range(player, anims_props);
            return;
        } else {
            player->move.destination = player->fight.target->move.pos;
            player->move.velocity = calculate_velocity(player->move.pos,
                player->move.destination);
            player->skin.anim_state = MOVEMENT_STATE;
            set_player_direction(player);
        }
    }
    move_player(player, dt, hitboxes);
    remove_arrow_anim(player->anims);
}
