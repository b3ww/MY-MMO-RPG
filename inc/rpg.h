/*
** EPITECH PROJECT, 2022
** rpg.h
** File description:
** RPG
*/

#pragma once

//////////////
// INCLUDES //
//////////////

    #include "struct.h"
    #include <stdio.h>
    #include "constants.h"

///////////////
// CONSTANTS //
///////////////

    /////////////////
    // ASSETS PATH //
    /////////////////


////////////
// MACROS //
////////////

    #define ABS(x)  x < 0 ? x * -1 : x

///////////////////////
// FUNCTIONS INCLUDE //
///////////////////////

void get_delta_t(rpg_t *rpg);
void manage_mouse_click(rpg_t *rpg, sfEvent evt);
void manage_keys_game(rpg_t *rpg, char code);
void move_cursor(cursor_t *cursor, v2i_t mpos);

// GLOOP
void gloop(rpg_t *rpg);
void gloop_event(rpg_t *rpg, sfEvent event);
void gloop_update_manager(rpg_t *rpg);

// Network
bool apply_received(rpg_t *rpg);

// SPLASH
void splash_manager(rpg_t *rpg);
void splash_draw(rpg_t *rpg);
void splash_update(rpg_t *rpg);

// GAME
void game_manager(rpg_t *rpg);

void game_event_manager(rpg_t *rpg);
void move_player_and_send(rpg_t *rpg);
void menu_consequences(rpg_t *rpg);

void game_update_manager(rpg_t *rpg);
void reload_player_skin(player_t *player);

void game_draw_manager(rpg_t *rpg);

void update_portals(portal_t *portals, player_t *player, rpg_t *rpg);
void update_ftb(fade_to_black_t *ftb, rpg_t *rpg);
void load_chest(rpg_t *rpg, scene_game_t *game);
bool send_death_signal(player_t *player, net_t *network);
void spawn_chest_when_kill(net_t *network, player_t *player,
scene_game_t *game, map_id_t map_id);
void try_open_chest(rpg_t *rpg);

// LAUNCHER
void launcher_manager(rpg_t *rpg);

void launcher_event_manager(rpg_t *rpg);
void launcher_button_released(player_t *player, scene_launcher_t *launcher,
sfMouseButtonEvent evt);
void draw_background_lcher(rpg_t *rpg, launcher_background_t bck);
void delete_char(char *str, int mode);
int is_containing_char(char *str, char c);
void set_text_move(char *pseudo_str, sfText *pseudo);
void play_button_clicked(rpg_t *rpg);

void launcher_update_manager(rpg_t *rpg);

void launcher_draw_manager(rpg_t *rpg);

void update_buttons(rpg_t *rpg);
void button_continue(rpg_t *rpg, button_t *but);
void update_settings_button_launcher(rpg_t *rpg, button_t *settings,
scene_t scene);
void update_right_button_launcher(rpg_t *rpg, scene_launcher_t *launcher);
void update_left_button_launcher(rpg_t *rpg, scene_launcher_t *launcher);
void update_exits_button_launcher(rpg_t *rpg, button_t *exits);

// SETTINGS
void settings_manager(rpg_t *rpg);
void settings_button_released(scene_settings_t *set,
sfMouseButtonEvent evt);
void settings_event_manager(rpg_t *rpg);
void settings_update_manager(rpg_t *rpg);
void settings_draw_manager(rpg_t *rpg);
void settings_back_button(rpg_t *rpg);
void settings_cancel_button(rpg_t *rpg);
void settings_music_button(rpg_t *rpg);
void settings_sound_released(scene_settings_t *settings,
sfMouseButtonEvent evt);
void settings_sound_button(rpg_t *rpg);
void update_network_infos(rpg_t *rpg, char *ip_port);

void *create_chat(void);
void send_chat_message(rpg_t *rpg, char *message);

void mouse_pressed_npc(rpg_t *rpg, sfEvent evt);
void update_player_stat(rpg_t *rpg);
void save_inventory(rpg_t *rpg);
void reset_chat_display(chat_t *chat);