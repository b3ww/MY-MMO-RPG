/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** game_draw
*/

#pragma once

    #include "struct.h"

void draw_players(sfRenderWindow *wd, player_t *players[50],
uss_t player_count);
void draw_particles(sfRenderWindow *window, anim_t * anims);
void draw_portals(sfRenderWindow *wd, portal_t *portals);
void draw_map_entities(sfRenderWindow *wd, map_t *map, bool draw);
void draw_button_game(sfRenderWindow *wd, scene_game_t *game);
void draw_chat(sfRenderWindow *wd, chat_t *chat);
void draw_cursor_drag(sfRenderWindow *wd, cursor_t *cursor);
void draw_hud(sfRenderWindow *wd, hud_t *hud);
void draw_items(rpg_t *rpg, inventory_t *inv, inventory_t *chest);
void draw_bin_smoke(sfRenderWindow *window, anim_t *anims);
