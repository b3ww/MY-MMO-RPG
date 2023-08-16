/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** destroy_player
*/

#include "struct.h"
#include "destroy.h"
#include "particle.h"

void destroy_player(player_t *player)
{
    sfRectangleShape_destroy(player->skin.hitbox);
    sfSprite_destroy(player->skin.sprite);
    sfTexture_destroy(player->skin.texture);
    sfClock_destroy(player->skin.anim_clock);
    sfClock_destroy(player->fight.attack_clock);
    sfClock_destroy(player->fight.regen_clock);
    sfText_destroy(player->stats.draw_name);
    sfText_destroy(player->fight.draw_kills);
    sfRectangleShape_destroy(player->stats.health_bar);
    free(player->fight.kills_str);
    destroy_anims(player->anims);
    destroy_portals(player->portal);
    free(player);
}
