/*
** EPITECH PROJECT, 2023
** inc/button
** File description:
** button struct
*/

#pragma once

    #include "share.h"

    #define SIZE_BUTTON_LINE 1250, 30
    #define BUTTON_JUMP 576
    #define PLAY_BUTTON_LINE_POS 208, 31
    #define SIZE_PLAY_BUTTON 64, 30
    #define SETTINGS_BUTTON_LINE_POS 0, 31
    #define SIZE_SETTINGS_BUTTON 98, 31
    #define BUTTON_SETTINGS_POS 901, 455
    #define DONATE_BUTTON_LINE_POS 7, 160
    #define SIZE_DONATE_BUTTON 84, 30
    #define EXIT_BUTTON_LINE_POS 495, 31
    #define SIZE_EXIT_BUTTON 67, 31
    #define BUTTON_EXIT_POS 996, 317
    #define BACK_BUTTON_LINE_POS 304, 128
    #define SIZE_BACK_BUTTON 64, 28
    #define BUTTON_BACK_POS 500, 585
    #define CANCEL_BUTTON_LINE_POS 102, 31
    #define SIZE_CANCEL_BUTTON 87, 31
    #define BUTTON_CANCEL_POS 55, 550
    #define ASSET_BUTTON "assets/ui/ui_buttons.png"

    #define ARROW_RIGHT_POS 49, 70
    #define ARROW_LEFT_POS 49, 38
    #define ARROW_BUTTON_LEFT_POS 25, 499
    #define ARROW_BUTTON_RIGHT_POS 250, 500
    #define ARROW_SIZE_LINE 65, 21
    #define ARROW_BUTTON_RECT 33, 21
    #define MUSIC_SOUND_ASSET_SIZE 48, 16
    #define SIZE_MUSIC_SOUND_BUTTON 16, 16
    #define MUSIC_BUTTON_LINE_POS 0, 0
    #define SOUND_BUTTON_LINE_POS 0, 16
    #define BUTTON_MUSIC_POS 1050, 200
    #define BUTTON_SOUND_POS 1000, 200
    #define JUMP_MUSIC_SOUND 16
    #define MUSIC_SOUND_JUMP 16, 0
    #define ASSET_FREE_LAUNCH "assets/ui/Free Platformer_UI_Buttons.png"

    #define BIN_JUMP 24
    #define SIZE_BIN_BUTTON 24, 33
    #define POS_BIN 1800, 525
    #define ASSET_BIN "assets/objects/decorations/bin.png"
typedef enum button_state {
    NONE,
    HOVER,
    RELEASED,
    PRESSED
} button_state_t;

typedef struct button {
    sfTexture *texture;
    sfSprite *sprite;
    void (*is_hover) (struct button *, sfMouseMoveEvent *);
    void (*is_released) (struct button *, sfMouseButtonEvent *);
    void (*is_pressed) (struct button *, sfMouseButtonEvent *);
    button_state_t state;
} button_t;

///////////////
/// PROGRAM ///
///////////////

button_t *create_button(char const *texture, v2f_t pos, v2f_t scale,
sfIntRect *area);
void button_pressed (button_t *button, sfMouseButtonEvent *evt);
void button_hover (button_t *button, sfMouseMoveEvent *move);
void button_released (button_t *button, sfMouseButtonEvent *evt);
