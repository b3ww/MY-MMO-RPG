/*
** EPITECH PROJECT, 2023
** csv_parser
** File description:
** parse
*/

#include "wcsv.h"
#include "tools.h"

static void set_formats(wcsv_t *parse, char *l_format, char *c_format)
{
    if (l_format) {
        parse->l_format = wstr_to_word_array(l_format, " ,");
        free(l_format);
    } else
        parse->l_format = NULL;
    if (c_format) {
        parse->c_format = wstr_to_word_array(c_format, " ,");
        free(c_format);
    } else
        parse->c_format = NULL;
}

wcsv_t *wcsv_parse(char *file_path, char *l_format, char *c_format)
{
    wcsv_t *ret = malloc(sizeof(wcsv_t));
    char *file = open_file(file_path);
    char *buffer = skip_ws(file);
    char **lines = wstr_to_word_array(buffer, "\n");
    int size = TABSIZE(lines);

    free(buffer);
    free(file);
    ret->file_plath = my_strdup(file_path);
    ret->content = malloc(sizeof(char **) * (size + 1));
    ret->content[size] = NULL;
    set_formats(ret, l_format ? my_strdup(l_format) : NULL, c_format ?
    my_strdup(c_format) : NULL);
    for (int i = 0; i < size; i++) {
        ret->content[i] = wstr_to_word_array(lines[i], ",");
        free(lines[i]);
    }
    free(lines);
    return ret;
}
