/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** struct
*/

#pragma once

    #include <SFML/Graphics.h>
    #include "network.h"
    #include "player_share.h"
    #include "shortcut.h"
    #include "player.h"
    #include "map.h"
    #include "cursor.h"
    #include "button.h"
    #include "scene_game.h"
    #include "scene_launcher.h"
    #include "scene_settings.h"
    #include "text.h"
    #include "launcher_background.h"
    #include "struct_particle.h"
    #include "inventory.h"
    #include "enum.h"
    #include "wcsv.h"
    #include "item.h"
    #include "audio_manager.h"
    #include "textures.h"
    #include "portals.h"
    #include "screen_effect.h"
    #include "chat.h"
    #include "hud.h"
    #include "splash.h"

////////////
/// ENUM ///
////////////

typedef enum game_layer {
    NONE_LAYER,
    MENU_LAYER,
    INVENTORY_LAYER,
    DEATH_LAYER
} game_layer_t;

////////////////
// STRUCTURES //
////////////////

typedef struct rpg {
    sfRenderWindow *wd;
    sfView *view;
    sfFont *font;
    texture_list_t *textures;

    cursor_t *cursor;
    sfVector2i mpos;

    sfClock *game_clock;
    sfInt64 previous_frame;
    float dt;
    fade_to_black_t *fade_to_black;
    bool full_screen;
    sfClock *timeout_clock;

    scene_t scene;
    game_layer_t game_layer;
    scene_launcher_t *launcher;
    scene_game_t *game;
    scene_settings_t *settings;
    splash_t *splash;

    pname_t player_name;
    player_t *players[50];
    uss_t player_count;
    player_t *target_player;

    hud_t *hud;

    net_t *network;
    uss_t server_port;
    sfIpAddress server_ip_address;

    anim_t *anims;
    anim_props_t *anims_props;

    map_t *map;

    audio_t *audio_manager;

    chat_t *chat;

    npc_t *npc;



    struct {
        int speed;
        int attack_damage;
        int health;
    } copy_player;

    struct {
        wcsv_t *items;
        wcsv_t *consos;
        wcsv_t *player_class;
        wcsv_t *maps;
        wcsv_t *textures;
        wcsv_t *stats;
        wcsv_t *inv_save;
    } file_config;
} rpg_t;
