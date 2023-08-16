/*
** EPITECH PROJECT, 2023
** src/gloop/game/update/game_update_button_continues
** File description:
** button continue update
*/

#include "rpg.h"
#include "destroy.h"

static void reset_player_to_launcher(player_t *player)
{
    sfSprite_setPosition(player->skin.sprite, (v2f_t){LAUNCHER_PLAYER_POS});
    player->skin.anim_rect.left = 0;
    player->skin.anim_rect.top = 0;
    sfSprite_setTextureRect(player->skin.sprite, player->skin.anim_rect);
}

void menu_consequences(rpg_t *rpg)
{
    if (rpg->game->menu_in_game) {
        rpg->game->menu_in_game = sfFalse;
        sfSprite_setPosition(rpg->game->menu->sprite, (v2f_t){5, 5});
        sfSprite_setScale(rpg->game->menu->sprite, (v2f_t){2.25, 2.25});
        rpg->scene = LAUNCHER;
        reset_player_to_launcher(rpg->players[0]);
        rpg->game->inv->is_open = sfFalse;
        rpg->game->chest->is_open = sfFalse;
        destroy_network(rpg->network);
        rpg->network = NULL;
        play_music(rpg->audio_manager, "menu");
    } else {
        rpg->game->menu_in_game = sfTrue;
        sfSprite_setPosition(rpg->game->menu->sprite, (v2f_t){850, 50});
        sfSprite_setScale(rpg->game->menu->sprite, (v2f_t){3.25, 3.25});
        rpg->game->inv->is_open = sfTrue;
    }
}

void button_continue(rpg_t *rpg, button_t *but)
{
    switch (but->state) {
    case HOVER: sfSprite_setTextureRect(but->sprite,
            (sfIntRect){BUTTON_JUMP, 0, 100, 30}); break;
    case PRESSED: sfSprite_setTextureRect(but->sprite,
            (sfIntRect){2 * BUTTON_JUMP, 0, 100, 30}); break;
    case RELEASED: sfSprite_setTextureRect(but->sprite,
            (sfIntRect){BUTTON_JUMP, 0, 100, 30});
        but->state = HOVER;
        rpg->game->menu_in_game = sfFalse;
        sfSprite_setPosition(rpg->game->menu->sprite, (v2f_t){5, 5});
        rpg->game->inv->is_open = sfFalse;
        break;
    default: sfSprite_setTextureRect(but->sprite,
        (sfIntRect){0, 0, 100, 30}); break;
    }
}
