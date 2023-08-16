/*
** EPITECH PROJECT, 2023
** inc/text
** File description:
** text.h
*/

#pragma once

///////////////
/// Include ///
///////////////

    #include "shortcut.h"
    #include "constants.h"

//////////////
/// Define ///
//////////////

    #define FONT "assets/fonts/upheavtt.ttf"
    #define TITLE_PO 550, 5
    #define PSEUDO_POS 48, 978
    #define IP_PORT_POS 790, 220

//////////////
/// Struct ///
//////////////

typedef struct text {
    sfFont *font;
    sfText *text;
    char *str;
    int max_length;
} text_t;

text_t *create_text(char const *str, int max_len, unsigned int character_size,
v2f_t pos);
void destroy_text(text_t *text);
