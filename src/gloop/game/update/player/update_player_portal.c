/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** update_player_portal
*/

#include "player.h"
#include "portals.h"
#include "destroy.h"

static void portal_despawn(player_t *player)
{
    if (player->portal->anim_state == P_DESPAWN) {
        if (player->portal->anim_rect.left == 7 * 64) {
            destroy_portals(player->portal);
            player->portal = NULL;
        }
    }
}

bool update_player_portal(player_t *player)
{
    if (player->portal == NULL)
        return false;
    if (player->portal->next) {
        destroy_portals(player->portal->next);
        player->portal->next = NULL;
    }
    animate_portal(player->portal);
    if (player->portal->anim_state == P_SPAWN)
        return true;
    if (player->portal->anim_state == P_IDLE) {
        player->skin.show_player = true;
        if (player->portal->anim_rect.left == 7 * 64) {
            player->portal->anim_state = P_DESPAWN;
            player->portal->anim_rect.left = 0;
        }
    }
    portal_despawn(player);
    return false;
}
