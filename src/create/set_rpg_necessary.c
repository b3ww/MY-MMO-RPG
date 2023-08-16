/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** set_rpg_necessary
*/

#include "rpg.h"
#include "create.h"

void set_rpg_necessary(rpg_t *rpg)
{
    rpg->wd = create_window();
    rpg->cursor = create_cursor();
    rpg->font = sfFont_createFromFile(FONT);
    rpg->game_clock = sfClock_create();
    rpg->previous_frame = sfClock_getElapsedTime(rpg->game_clock).microseconds;
    rpg->view = sfView_createFromRect((sfFloatRect){0, 0, WIDTH, HEIGHT});
    rpg->file_config.items = wcsv_parse("config/items.csv", ITEMS_LHEAD,
        ITEMS_CHEAD);
    rpg->file_config.consos = wcsv_parse("config/consos.csv",
        "name, desc, inf, txt_path", NULL);
    rpg->file_config.player_class = wcsv_parse("config/player_class.csv",
        PLAYER_CLASS_LHEAD, NULL);
    rpg->file_config.maps = wcsv_parse("config/map.csv", LFORMAT_MAPS, NULL);
    rpg->file_config.textures = wcsv_parse("config/entity.csv", "letter, \
    path", NULL);
    rpg->file_config.stats = wcsv_parse("config/stats.csv", ITEMS_STATS, NULL);
}
