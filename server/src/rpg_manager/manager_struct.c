/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski [SSH: 193.70.40.62]
** File description:
** manager_struct
*/

#include <stdio.h>
#include "rpg_online_manager.h"
#include "share.h"
#include <stdlib.h>

static char *get_item(char ***items)
{
    int r = rand() % 100;
    int item_type = (rand() % 5);
    int begin = 0;

    if (!percent(45))
        return NULL;
    if (r < 50)
        begin = 0;
    if (r >= 50 && r < 80)
        begin = 1;
    if (r >= 80 && r < 90)
        begin = 2;
    if (r >= 90)
        begin = 3;
    return items[item_type * begin][0];
}

static char ***get_chest(char ***items)
{
    char ***ret = malloc(sizeof(char **) * NB_CHEST);

    for (int i = 0; i < NB_CHEST; i++) {
        ret[i] = malloc(sizeof(char *) * 12);
        for (int j = 0; j < 12; j++)
            ret[i][j] = get_item(items);
    }
    return ret;
}

manager_t *init_manager(void)
{
    manager_t *ret = malloc(sizeof(manager_t));

    ret->items_csv = wcsv_parse(ITEMS_CF, NULL, NULL);
    ret->chest = get_chest(ret->items_csv->content);
    return ret;
}
