/*
** EPITECH PROJECT, 2022
** mouse
** File description:
** mouse
*/

#include "rpg.h"
#include "rpg_particles.h"

static void click_attack_player(rpg_t *rpg)
{
    rpg->players[0]->fight.target = NULL;
    if (rpg->target_player != NULL) {
        rpg->players[0]->fight.target = rpg->target_player;
    }
}

void manage_mouse_click(rpg_t *rpg, sfEvent evt)
{
    sfFloatRect rect_inv = sfSprite_getGlobalBounds(rpg->game->inv->sprite);
    sfFloatRect rect_chest = sfSprite_getGlobalBounds(
        rpg->game->chest->sprite);

    if (rpg->game->menu_in_game || rpg->game->menu->state != NONE ||
    (rpg->game->inv->is_open && sfFloatRect_contains(&rect_inv,
    evt.mouseButton.x, evt.mouseButton.y)) || (rpg->game->inv->is_open &&
    sfFloatRect_contains(&rect_chest, evt.mouseButton.x, evt.mouseButton.y))
    || rpg->players[0]->stats.health <= 0)
        return;
    click_attack_player(rpg);
    move_player_and_send(rpg);
}
