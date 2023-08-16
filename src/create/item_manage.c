/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** item_manage
*/

#include "inventory.h"
#include "wcsv.h"
#include "rpg.h"

item_type_t get_item_type(rpg_t *rpg, char *name)
{
    wcsv_t *conf = rpg->file_config.items;

    if (wcsv_get(conf, ((wreq_t){name, VALUE, NULL, LINE})))
        return UNCONSO;
    conf = rpg->file_config.consos;
    if (wcsv_get(conf, ((wreq_t){name, VALUE, NULL, LINE})))
        return CONSO;
    return -1;
}
