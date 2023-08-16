/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** draw_button_game
*/

#include "inv_item_share.h"

void draw_button_game(sfRenderWindow *wd, scene_game_t *game)
{
    sfRenderWindow_drawSprite(wd, game->menu->sprite, NULL);
    if (game->menu_in_game) {
        sfRenderWindow_drawSprite(wd, game->exits->sprite, NULL);
        sfRenderWindow_drawSprite(wd, game->save->sprite, NULL);
        sfRenderWindow_drawSprite(wd, game->load->sprite, NULL);
        sfRenderWindow_drawSprite(wd, game->settings->sprite, NULL);
        sfRenderWindow_drawSprite(wd, game->continues->sprite, NULL);
    }
}
