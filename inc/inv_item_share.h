/*
** EPITECH PROJECT, 2023
** inc/inv_item_share
** File description:
** check your malloc!
*/

#pragma once

    #include "rpg.h"

    #define CHEST_DELETE_BUTTON 1880, 56, 42, 42
    #define INV_DELETE_BUTTON 1880, 362, 42, 42

item_type_t get_item_type(rpg_t *rpg, char *name);

void manage_mouse_move(rpg_t *rpg, inventory_t *inv, sfEvent evt);
void manage_mouse_pressed(rpg_t *rpg, sfEvent evt);
void manage_mouse_released(rpg_t *rpg, inventory_t *inv, sfEvent evt);
void manage_mouse_inventory(rpg_t *rpg, sfEvent evt);
void game_mouse_button_clicked(rpg_t *rpg, inventory_t *inv, sfEvent evt);
void draw_items(rpg_t *rpg, inventory_t *inv, inventory_t *chest);
void chest_clicked(rpg_t *rpg, sfEvent evt);
void button_manager(rpg_t *rpg, scene_game_t *game);
