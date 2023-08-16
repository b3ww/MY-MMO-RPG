/*
** EPITECH PROJECT, 2023
** csv_parser
** File description:
** destroy_csv
*/

#include "wcsv.h"

void wcsv_destroy(wcsv_t *parse)
{
    for (int i = 0; parse->content[i]; i++) {
        for (int j = 0; parse->content[i][j]; j++)
            free(parse->content[i][j]);
        free(parse->content[i]);
    }
    if (parse->l_format) {
        for (int i = 0; parse->l_format[i]; i++)
            free(parse->l_format[i]);
        free(parse->l_format);
    }
    if (parse->c_format) {
        for (int i = 0; parse->c_format[i]; i++)
            free(parse->c_format[i]);
        free(parse->c_format);
    }
    free(parse->content);
    free(parse->file_plath);
    free(parse);
}
