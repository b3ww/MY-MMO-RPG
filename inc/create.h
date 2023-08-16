/*
** EPITECH PROJECT, 2022
** create.h
** File description:
** UPDATE
*/

#pragma once

    #include "rpg.h"
    #include <stdlib.h>
    #include "wcsv.h"

    #define ASSET_CURSOR_ARROW "assets/ui/cursors/cursor_default.png"
    #define ASSET_CURSOR_SELECT "assets/ui/cursors/cursor_select.png"
    #define ASSET_CURSOR_SELECT_TAP "assets/ui/cursors/cursor_select_tap.png"
    #define ASSET_BACKGROUND "assets/maps/0.png"

rpg_t *create_manager(void);
void set_rpg_necessary(rpg_t *rpg);
sfRenderWindow *create_window(void);
cursor_t *create_cursor(void);

sfText *create_draw_text(char *name, sfFont *font);
sfRectangleShape *create_health_bar(void);
player_t *create_player_me(sfFont *font, pname_t player_name,
wcsv_t *player_class_csv);
void set_skin(player_t *player, player_server_t *player_server,
int player_found);
player_t *set_player_client(player_t *player, player_server_t *player_server,
int player_found, sfFont *font);
scene_settings_t *create_settings(void);
anim_props_t *create_anims_props_list(texture_list_t *textures);
inventory_t *create_inventory(char load);
scene_game_t *create_scene_game(void);

item_t *create_item(rpg_t *rpg, char *name);
texture_list_t *load_textures(void);

portal_t *create_portal(sfTexture *texture);
void append_portal(portal_t **portal_list, portal_t *to_append);

fade_to_black_t *create_fade_to_black(void);
map_t *load_map(rpg_t *rpg, map_id_t id);
void parse_chat_message(rpg_t *rpg, char *message);
bool stack_entities(map_t *to_stack, char **to_parse, v2f_t size,
    rpg_t *rpg);
hud_t *create_hud(void);
slot_t *create_item_manager(rpg_t *rpg, char *name);
void add_item_to_inventory(rpg_t *rpg, char *name);
slot_t *create_item_manager(rpg_t *rpg, char *name);
splash_t *create_splash(void);
