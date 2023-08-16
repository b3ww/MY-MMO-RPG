/*
** EPITECH PROJECT, 2023
** inc/scene_menu_game
** File description:
** scene menu in game
*/

#pragma once

    #include "button.h"

    #define AREA_CONT 96, 64
    #define AREA_QUIT 62, 64
    #define ARE_CREDITS 80, 64
    #define BT_CONTINUE 208, 0 AREA_CONT
    #define BT_QUIT 592, 0, AREA_QUIT
    #define BT_CREDITS 459, 0 ARE_CREDITS
    #define UI_BUTTON_PATH "./assets/ui/Free Platformer_UI_Buttons.png"

typedef struct scene_menu_game {
    sfRectangleShape *background;
    button_t *credits;
    button_t *quit;
} scene_menu_game_t;
