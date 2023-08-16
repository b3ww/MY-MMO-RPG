/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** apply
*/

#include "wcsv.h"
#include <stdio.h>

int wcsv_apply(wcsv_t *parse)
{
    FILE *file = fopen(parse->file_plath, "w");
    char *tmp = NULL;
    int height = TABSIZE(parse->content);
    int width = 0;

    if (!file)
        return -1;
    for (int i = 0; i < height; i++) {
        width = TABSIZE(parse->content[i]);
        for (int j = 0; j < width; j++) {
            tmp = parse->content[i][j];
            fwrite(tmp, 1, strlen(tmp), file);
            j + 1 != width ? fwrite(",", 1, 1, file) : 0;
        }
        if (i + 1 != height)
            fwrite("\n", 1, 1, file);
    }
    return 0;
}
