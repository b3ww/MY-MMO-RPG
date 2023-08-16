/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** update_portals
*/

#include "portals.h"
#include "struct.h"
#include "tools.h"

static bool is_player_in_portal(sfSprite *portal, sfSprite *player)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(player);
    sfFloatRect portal_bounds = sfSprite_getGlobalBounds(portal);
    float x = portal_bounds.left + portal_bounds.width / 2;
    float y = portal_bounds.top + portal_bounds.height / 2;

    if (sfFloatRect_contains(&bounds, x, y))
        return true;
    return false;
}

void update_portal(portal_t *portal, player_t *player, rpg_t *rpg)
{
    animate_portal(portal);
    if (is_player_in_portal(portal->sprite, player->skin.sprite)) {
        if (portal->anim_state != P_DESPAWN) {
            portal->anim_rect.left = 0;
        }
        portal->anim_state = P_DESPAWN;
        if (my_strcmp(player->name, rpg->players[0]->name) == 0) {
            rpg->fade_to_black->active = true;
            rpg->fade_to_black->portal = portal;
            player->skin.show_player = false;
        }
    }
}

void update_portals(portal_t *portals, player_t *player, rpg_t *rpg)
{
    portal_t *portal = portals;

    for (; portal != NULL; portal = portal->next)
        update_portal(portal, player, rpg);
}
