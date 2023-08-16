/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** destroy_csv
*/

#include "destroy.h"

void destroy_csv(rpg_t *rpg)
{
    wcsv_destroy(rpg->file_config.consos);
    wcsv_destroy(rpg->file_config.inv_save);
    wcsv_destroy(rpg->file_config.items);
    wcsv_destroy(rpg->file_config.maps);
    wcsv_destroy(rpg->file_config.player_class);
    wcsv_destroy(rpg->file_config.stats);
    wcsv_destroy(rpg->file_config.textures);
}
