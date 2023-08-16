/*
** EPITECH PROJECT, 2022
** free
** File description:
** free all of the game structure
*/

#include "rpg.h"
#include "destroy.h"
#include "particle.h"
#include "wcsv.h"
#include <stdlib.h>

void destroy_next(rpg_t *rpg)
{
    destroy_hud(rpg->hud);
    destroy_splash(rpg->splash);
    destroy_audio_manager(rpg->audio_manager);
    free(rpg);
}

void destroy_manager(rpg_t *rpg)
{
    destroy_cursor(rpg->cursor);
    destroy_map(rpg->map);
    for (int i = 0; i < rpg->player_count; i++)
        destroy_player(rpg->players[i]);
    destroy_network(rpg->network);
    destroy_launcher(rpg->launcher);
    destroy_game(rpg->game);
    destroy_settings(rpg->settings);
    sfFont_destroy(rpg->font);
    sfClock_destroy(rpg->game_clock);
    sfView_destroy(rpg->view);
    sfRenderWindow_destroy(rpg->wd);
    destroy_anims(rpg->anims);
    destroy_anims_props(rpg->anims_props);
    destroy_textures(rpg->textures);
    destroy_fade_to_black(rpg->fade_to_black);
    destroy_csv(rpg);
    destroy_chat(rpg->chat);
    destroy_npc(rpg);
    destroy_next(rpg);
}
