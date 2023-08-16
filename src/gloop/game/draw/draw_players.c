/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** draw_players
*/

#include "game_draw.h"
#include "scene_game.h"

void draw_chest(sfRenderWindow *wd, chest_t *temp)
{
    while (temp) {
        if (!temp->visited)
            sfRenderWindow_drawSprite(wd, temp->sprite, NULL);
        temp = temp->next;
    }
}

static void draw_one(sfRenderWindow *wd, player_t *player)
{
    if (!player->skin.show_player)
        return;
    sfRenderWindow_drawSprite(wd, player->skin.sprite,
        NULL);
    sfRenderWindow_drawText(wd, player->stats.draw_name, NULL);
    sfRenderWindow_drawText(wd, player->fight.draw_kills, NULL);
    sfRenderWindow_drawRectangleShape(wd, player->stats.health_bar,
        NULL);
    if (player->skin.show_hitbox) {
        sfRenderWindow_drawRectangleShape(wd, player->skin.hitbox, NULL);
    }
}

void draw_players(sfRenderWindow *wd, player_t *players[50],
uss_t player_count)
{
    for (int i = player_count - 1; i >= 0; i--) {
        draw_one(wd, players[i]);
        draw_particles(wd, players[i]->anims);
        draw_portals(wd, players[i]->portal);
    }
}
