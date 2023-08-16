/*
** EPITECH PROJECT, 2023
** src/destroy/destroy_scene_game
** File description:
** destroy scene game
*/

#include "destroy.h"

void destroy_one_chest(chest_t *chest)
{
    sfSprite_destroy(chest->sprite);
    sfTexture_destroy(chest->texture);
    free(chest);
}

void destroy_list_chest(chest_t *chest)
{
    if (!chest)
        return;
    destroy_list_chest(chest->next);
    destroy_one_chest(chest);
}

void destroy_game(scene_game_t *game)
{
    destroy_inventory(game->inv);
    destroy_inventory(game->chest);
    destroy_button(game->settings);
    destroy_button(game->exits);
    destroy_button(game->save);
    destroy_button(game->bin);
    destroy_button(game->load);
    destroy_button(game->menu);
    destroy_button(game->continues);
    destroy_list_chest(game->l_chest);
    sfRectangleShape_destroy(game->opacity);
    free(game);
}
