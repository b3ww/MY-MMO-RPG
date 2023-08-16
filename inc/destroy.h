/*
** EPITECH PROJECT, 2022
** destroy.h
** File description:
** FREE
*/

#pragma once

    #include "rpg.h"

    #include <SFML/Graphics.h>
    #include <stdlib.h>

void destroy_manager(rpg_t *rpg);
void destroy_cursor(cursor_t *cursor);
void destroy_map(map_t *map);
void destroy_network(net_t *net);
void destroy_button(button_t *button);
void destroy_launcher(scene_launcher_t *launcher);
void destroy_player(player_t *player);
void destroy_settings(scene_settings_t *settings);
void destroy_button(button_t *button);
void destroy_inventory(inventory_t *inv);
void wcsv_destroy(wcsv_t *parse);
void destroy_item(item_t *item);
void destroy_consos(conso_t *item);
void destroy_game(scene_game_t *game);
void my_freetab(char **tab);
void destroy_textures(texture_list_t *textures);
void destroy_portals(portal_t *portal);
void destroy_fade_to_black(fade_to_black_t *fade_to_black);
void destroy_csv(rpg_t *rpg);
void destroy_chat(chat_t *chat);
void destroy_slot(slot_t *slot);
void destroy_npc(rpg_t *rpg);
void destroy_hud(hud_t *hud);
void destroy_all_items(inventory_t *inv);
void destroy_splash(splash_t *splash);
