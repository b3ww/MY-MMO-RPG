/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** tools
*/

#pragma once

    #include "shortcut.h"
    #include "player.h"
    #include "textures.h"
    #include "wcsv.h"

void print_help(void);
int my_strlen(const char *str);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strnbr(unsigned int input);
void center_circle_origin(sfCircleShape *circleShape);
sfColor get_color(player_color_t enum_color);
int create_player_id(char *name);
char **wrtab_copy(char **tab);
char *skip_ws(char *str);
char **wstr_to_word_array(char *str, char *sample);
float get_distance(v2f_t a, v2f_t b);
sfTexture *get_texture_from_id(texture_list_t *textures, uss_t id);
void delete_char(char *str, int mode);
int my_getnbr(char const *str);
char *get_pclass_str(player_class_t pclass);
int get_csv_value(wcsv_t *pcsv, char *class, char *column);
void center_sprite(sfSprite *sprite);
