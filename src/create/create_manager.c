/*
** EPITECH PROJECT, 2022
** create_manager
** File description:
** create_manager
*/

#include "rpg.h"
#include "create.h"
#include "audio_manager.h"
#include "tools.h"
#include "chat.h"
#include <stdlib.h>
#include "rpg_particles.h"

void inv_save(rpg_t *rpg)
{
    char **line = NULL;
    rpg->file_config.inv_save = wcsv_parse("config/inv_save.csv", "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11", NULL);
    line = rpg->file_config.inv_save->content[1];
    for (int i = 0; i < 12; i++) {
        if (!my_strcmp("none", line[i]))
            continue;
        rpg->game->inv->slots[i] = create_item_manager(rpg, line[i]);
    }
}

void create_of_create(rpg_t *rpg)
{
    rpg->textures = load_textures();
    rpg->launcher = create_scene_launcher();
    rpg->settings = create_settings();
    rpg->game = create_scene_game();
    rpg->players[0] = create_player_me(rpg->font, rpg->player_name,
        rpg->file_config.player_class);
    rpg->fade_to_black = create_fade_to_black();
    rpg->hud = create_hud();
    rpg->map = NULL;
    inv_save(rpg);
    rpg->anims_props = create_anims_props_list(rpg->textures);
    rpg->chat = create_chat();
    rpg->audio_manager = create_audio_manager();
    rpg->splash = create_splash();
    rpg->anims = NULL;
    if (rpg->scene == SPLASH)
        anim_append(&rpg->anims, create_smoke(get_anims_props(rpg->anims_props,
            SMOKE_ANIM)));
}

rpg_t *create_manager(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    my_strcpy(rpg->player_name, "Pseudo");
    set_rpg_necessary(rpg);
    // rpg->scene = LAUNCHER;
    rpg->scene = SPLASH;
    create_of_create(rpg);
    rpg->timeout_clock = NULL;
    rpg->network = NULL;
    rpg->server_ip_address = sfIpAddress_fromString("127.0.0.1");
    rpg->game_layer = NONE_LAYER;
    rpg->player_count = 1;
    rpg->target_player = NULL;
    rpg->full_screen = false;
    rpg->npc = load_npc();
    sfRenderWindow_setMouseCursorVisible(rpg->wd, sfFalse);
    sfRenderWindow_setFramerateLimit(rpg->wd, FPS);
    return rpg;
}
