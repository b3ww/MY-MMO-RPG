/*
** EPITECH PROJECT, 2022
** draw
** File description:
** draw each element on the screen
*/

#include "rpg.h"
#include "game_draw.h"
#include "tools.h"

static void draw_game(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->wd, rpg->map->background_sprite, NULL);
    draw_chest(rpg->wd, rpg->game->l_chest);
    draw_map_entities(rpg->wd, rpg->map, 0);
    draw_players(rpg->wd, rpg->players, rpg->player_count);
    draw_map_entities(rpg->wd, rpg->map, 1);
    draw_portals(rpg->wd, rpg->map->portals);
    if (rpg->map->id == 0 || rpg->map->id == 2 || rpg->map->id == 4) {
        sfSprite_setPosition(rpg->npc->sprite,
        rpg->npc->capy[(int)rpg->map->id / 2].pos);
        sfRenderWindow_drawSprite(rpg->wd, rpg->npc->sprite, NULL);
    }
    draw_particles(rpg->wd, rpg->anims);
    draw_hud(rpg->wd, rpg->hud);
    if (rpg->game->menu_in_game)
        sfRenderWindow_drawRectangleShape(rpg->wd, rpg->game->opacity, NULL);
    draw_items(rpg, rpg->game->inv, rpg->game->chest);
    draw_bin_smoke(rpg->wd, rpg->anims);
    draw_cursor_drag(rpg->wd, rpg->cursor);
    if (rpg->chat->to_display)
        draw_chat(rpg->wd, rpg->chat);
    draw_button_game(rpg->wd, rpg->game);
}

void game_draw_manager(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->wd, sfBlack);
    if (rpg->map != NULL)
        draw_game(rpg);
    sfRenderWindow_drawRectangleShape(rpg->wd, rpg->fade_to_black->rect, NULL);
    sfRenderWindow_drawSprite(rpg->wd, rpg->cursor->sprite, NULL);
    sfRenderWindow_display(rpg->wd);
}
