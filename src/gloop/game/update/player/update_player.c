/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** update_player
*/

#include "player.h"
#include "rpg_particles.h"

static void manage_death(player_t *player)
{
    if (player->stats.health < 0 && player->skin.anim_state != DEATH_STATE) {
        player->stats.health = 0;
        player->skin.anim_rect.left = 0;
        player->skin.anim_state = DEATH_STATE;
    }
}

static void manage_regen(player_t *player)
{
    if (GET_CLOCK_SEC(player->fight.regen_clock) > 1) {
        if (player->stats.health <= 0)
            return;
        if (player->stats.health >= player->stats.max_health)
            player->stats.health = player->stats.max_health;
        else
            player->stats.health += player->stats.regen;
        sfClock_restart(player->fight.regen_clock);
    }
}

void update_player(player_t *player, double dt, anim_props_t *anim_props,
bool **hitboxes)
{
    sfSprite_setPosition(player->skin.sprite, player->move.pos);
    update_anims(&player->anims, dt);
    manage_regen(player);
    move_player_ui(player);
    if (update_player_portal(player))
        return;
    attack_or_move(player, dt, anim_props, hitboxes);
    manage_death(player);
    animate_player(player);
}
