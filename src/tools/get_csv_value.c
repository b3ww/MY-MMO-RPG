/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** get_csv_value
*/

#include "tools.h"

int get_csv_value(wcsv_t *pcsv, char *class, char *column)
{
    return my_getnbr((char *)wcsv_get(pcsv, (wreq_t){class, VALUE, column,
        LFORMAT}));
}
