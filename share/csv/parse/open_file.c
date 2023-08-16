/*
** EPITECH PROJECT, 2023
** csv_parser
** File description:
** open_file
*/

#include "wcsv.h"
#include <stdio.h>

char *open_file(char *path)
{
    char *content_ret = NULL;
    struct stat st;
    int fd = 0;

    if ((stat(path, &st)) == -1)
        return NULL;
    content_ret = malloc(sizeof(char) * (st.st_size + 1));
    content_ret[st.st_size] = '\0';
    if ((fd = open(path, O_RDONLY)) == -1)
        return NULL;
    read(fd, content_ret, st.st_size);
    close(fd);
    return content_ret;
}
