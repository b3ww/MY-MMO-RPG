/*
** EPITECH PROJECT, 2023
** src/gloop/game/update/game_update_button
** File description:
** game update button
*/

#include "rpg.h"
#include "destroy.h"

static void button_bin(rpg_t *rpg, scene_game_t *game)
{
    switch (game->bin->state) {
    case HOVER: sfSprite_setTextureRect(game->bin->sprite,
        (sfIntRect){0, 0, SIZE_BIN_BUTTON}); break;
    case PRESSED: sfSprite_setTextureRect(game->bin->sprite,
        (sfIntRect){BIN_JUMP, 0, SIZE_BIN_BUTTON}); break;
    case RELEASED: sfSprite_setTextureRect(game->bin->sprite,
        (sfIntRect){0, 0, SIZE_BIN_BUTTON});
        if (rpg->cursor->drag) {
            destroy_slot(rpg->cursor->drag);
            rpg->cursor->drag = NULL;
        }
        break;
    default: sfSprite_setTextureRect(game->bin->sprite,
        (sfIntRect){BIN_JUMP, 0, SIZE_BIN_BUTTON}); break;
    }
}

void button_load_save(rpg_t *rpg, button_t *but)
{
    switch (but->state) {
    case HOVER: sfSprite_setTextureRect(but->sprite,
            (sfIntRect){BUTTON_JUMP, 0, 67, 30}); break;
    case PRESSED: sfSprite_setTextureRect(but->sprite,
            (sfIntRect){2 * BUTTON_JUMP, 0, 67, 30});
            save_inventory(rpg);
            break;
    case RELEASED: sfSprite_setTextureRect(but->sprite,
            (sfIntRect){BUTTON_JUMP, 0, 67, 30});
        but->state = HOVER;
        break;
    default: sfSprite_setTextureRect(but->sprite,
        (sfIntRect){0, 0, 67, 30}); break;
    }
}

void button_menu_game(rpg_t *rpg, button_t *menu)
{
    switch (menu->state) {
    case HOVER: sfSprite_setTextureRect(menu->sprite,
            (sfIntRect){BUTTON_JUMP, 0, 67, 30}); break;
    case PRESSED: sfSprite_setTextureRect(menu->sprite,
            (sfIntRect){2 * BUTTON_JUMP, 0, 67, 30}); break;
    case RELEASED: sfSprite_setTextureRect(menu->sprite,
            (sfIntRect){BUTTON_JUMP, 0, 67, 30});
        menu->state = HOVER;
        menu_consequences(rpg); break;
    default: sfSprite_setTextureRect(menu->sprite,
        (sfIntRect){0, 0, 67, 30}); break;
    }
}

void button_manager(rpg_t *rpg, scene_game_t *game)
{
    button_bin(rpg, game);
    button_load_save(rpg, rpg->game->load);
    button_load_save(rpg, rpg->game->save);
    button_menu_game(rpg, rpg->game->menu);
    update_settings_button_launcher(rpg, rpg->game->settings, GAME);
    update_exits_button_launcher(rpg, rpg->game->exits);
    button_continue(rpg, rpg->game->continues);
}
