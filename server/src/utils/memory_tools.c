/*
** EPITECH PROJECT, 2023
** MMOPRG_ONLINE [SSH]
** File description:
** memory_tools
*/

#include "wnetcsfml.h"

void *wmcpy(const void *to_copy, size_t size)
{
    void *ret = malloc(size);
    char *src = (char *)to_copy;
    char *dest = (char *)ret;

    for (int i = 0; i < size; i++)
        dest[i] = src[i];
    return ret;
}

void *memorycat(void *m1, size_t size_1, void *m2, size_t size_2)
{
    void *ret = malloc(size_1 + size_2);
    char *src1 = NULL;
    char *src2 = NULL;
    char *dest = NULL;

    if (ret != NULL) {
        dest = (char *)ret;
        src1 = (char *)m1;
        src2 = (char *)m2;
        for (size_t i = 0; i < size_1; i++)
            dest[i] = src1[i];
        for (size_t i = 0; i < size_2; i++)
            dest[size_1 + i] = src2[i];
        return ret;
    }
    return NULL;
}
