/*
** EPITECH PROJECT, 2023
** inc/scene_game
** File description:
** scene game
*/

#pragma once

    #include "button.h"
    #include "inventory.h"
    #include <SFML/Graphics.h>
    #include "chest.h"

typedef struct scene_game {
    sfBool menu_in_game;
    button_t *menu;
    button_t *exits;
    button_t *save;
    button_t *load;
    button_t *settings;
    button_t *continues;
    button_t *bin;
    chest_t *l_chest;
    sfRectangleShape *opacity;
    inventory_t *inv;
    inventory_t *chest;
    inventory_t *other;
} scene_game_t;

chest_t *create_chest(chest_t *list, v2f_t pos);
void draw_chest(sfRenderWindow *wd, chest_t *chest);
