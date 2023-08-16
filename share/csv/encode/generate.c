/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** generate
*/

#include <stdio.h>

int generate_csv(char *path, int width, int height)
{
    FILE *file = fopen(path, "w");

    if (!file)
        return -1;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            fwrite("none", 1, 4, file);
            j + 1 != height ? fwrite(",", 1, 1, file) : 0;
        }
        if (i + 1 != width)
            fwrite("\n", 1, 1, file);

    }
    fclose(file);
    return 0;
}
