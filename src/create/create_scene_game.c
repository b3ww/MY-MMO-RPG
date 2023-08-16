/*
** EPITECH PROJECT, 2023
** src/create/create_scene_game
** File description:
** create scene game
*/

#include "create.h"
#include "button.h"

static void create_button_game(scene_game_t *game)
{
    sfIntRect area_exit = {EXIT_BUTTON_LINE_POS, SIZE_BUTTON_LINE};
    sfIntRect area_menu = {208, 96, SIZE_BUTTON_LINE};
    sfIntRect area_sett = {SETTINGS_BUTTON_LINE_POS, SIZE_BUTTON_LINE};
    sfIntRect area_save = {208, 157, SIZE_BUTTON_LINE};
    sfIntRect area_load = {398, 127, SIZE_BUTTON_LINE};

    game->bin = create_button(ASSET_BIN, (v2f_t){POS_BIN},
        (v2f_t){3.25, 3.25}, NULL);
    game->menu = create_button(ASSET_BUTTON, (v2f_t){5, 5},
        (v2f_t){2.25, 2.25}, &area_menu);
    game->load = create_button(ASSET_BUTTON, (v2f_t){850, 150},
        (v2f_t){3.25, 3.25}, &area_load);
    game->save = create_button(ASSET_BUTTON, (v2f_t){850, 250},
        (v2f_t){3.25, 3.25}, &area_save);
    game->settings = create_button(ASSET_BUTTON,
        (v2f_t){852, 350}, (v2f_t){3.25, 3.25}, &area_sett);
    game->exits = create_button(ASSET_BUTTON, (v2f_t){850, 450},
        (v2f_t){3.25, 3.25}, &area_exit);
    game->continues = create_button(ASSET_BUTTON, (v2f_t){850, 550},
        (v2f_t){3.25, 3.25}, &((sfIntRect){0, 64, SIZE_BUTTON_LINE}));
}

scene_game_t *create_scene_game(void)
{
    scene_game_t *game = malloc(sizeof(scene_game_t));

    game->inv = create_inventory(0);
    game->chest = create_inventory(1);
    game->menu_in_game = sfFalse;
    game->opacity = sfRectangleShape_create();
    game->l_chest = NULL;
    sfRectangleShape_setSize(game->opacity, (v2f_t){WIDTH, HEIGHT});
    sfRectangleShape_setFillColor(game->opacity, sfColor_fromRGBA(0, 0, 0,
        180));
    create_button_game(game);
    return game;
}
