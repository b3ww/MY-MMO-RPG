/*
** EPITECH PROJECT, 2023
** csv_parser
** File description:
** wcsv
*/

#pragma once

    #include <unistd.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdbool.h>

    #define ISWS(__c) (__c == ' ' || __c == '\t' ? true : false)
    #define TABSIZE(tab) ({int _i = 0; while (tab[_i]){_i++;} _i;})
    #define TABFREE(tab) ({for (int _i = 0; tab[_i]; _i++){free(tab[_i]);}})

/*--TYPE--*/
typedef struct csv_stock {
    char *file_plath;
    char ***content;
    char **l_format;
    char **c_format;
} wcsv_t;

typedef enum csv_value_type {
    LINE,
    COLUMN,
    VALUE,
    LFORMAT,
    CFORMAT
} cvt_t;

typedef struct parse_request {
    void *know;
    cvt_t know_type;
    void *want;
    cvt_t want_type;
} wcsv_req_t;

typedef wcsv_req_t wreq_t;
/*--------*/

/*--PARSE--*/
int my_tablen(char *const *tab);
wcsv_t *wcsv_parse(char *file_path, char *l_format, char *c_format);
char **get_line_with_value(wcsv_t *parse, char *value);
char **get_column_with_value(wcsv_t *parse, char *value);
void *wcsv_get(wcsv_t *parse, wreq_t parse_request);
/*---------*/

/*--ENCODE--*/
int generate_csv(char *path, int width, int height);
int wcsv_apply(wcsv_t *parse);
/*----------*/

/*--TOOLS--*/
char *open_file(char *path);
/*---------*/

/*______________________ITEMS_______________________*/
    #define ITEMS_FILE "config/items.csv"
    #define ITEMS_LHEAD "name, description, rarity, text_path"
    #define ITEMS_STATS "rarity, type, attack_damage, attack_speed, range, \
    max_health, movement_speed"
    #define ITEMS_CHEAD NULL
    #define PLAYER_CLASS_LHEAD "name,attack_damage, attack_speed, range_type, \
range, projectile_speed, max_health, regen, max_mana, movement_speed"
/*__________________________________________________*/

    #define LFORMAT_MAPS "id,assets,data,color,fight"
