/*
** EPITECH PROJECT, 2023
** inc/background
** File description:
** background create
*/

#pragma once

    #include <SFML/Graphics.h>

    #define ASSET_BACKGROUND_GREEN "assets/background/background_green.png"
    #define ASSET_BACKGROUND_RED "assets/background/background_red.png"
    #define ASSET_BACKGROUND_BLUE "assets/background/background_blue.png"

//////////////
/// Struct ///
//////////////

typedef struct launcher_background {
    sfTexture *texture_red;
    sfTexture *texture_green;
    sfTexture *texture_blue;
    sfSprite *sprite_green;
    sfSprite *sprite_red;
    sfSprite *sprite_blue;
} launcher_background_t;
