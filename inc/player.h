/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** player
*/

#pragma once

    #include "player_share.h"
    #include "struct_particle.h"
    #include "portals.h"
    #include "map.h"
    #include "chest.h"

    #define IDLE_ANIM_SPEED 0.25

    #define HB_MAX_WIDTH 70
    #define HB_MAX_HEIGHT 7

    #define CAPY_PATH "assets/entity/npc/capy.png"

typedef enum direction {
    RIGHT,
    DOWN,
    LEFT,
    UP
} direction_t;

typedef struct player_stats {
    sfText *draw_name;
    int max_health;
    int health;
    int previous_health;
    int regen;
    sfRectangleShape *health_bar;
    int max_mana;
    int mana;
    uss_t level;
    int exp;
} player_stats_t;

typedef struct player_skin {
    player_class_t pclass;
    player_color_t color;
    sfIntRect anim_rect;
    anim_state_t anim_state;
    sfClock *anim_clock;
    sfTexture *texture;
    sfSprite *sprite;
    v2f_t scale;
    sfRectangleShape *hitbox;
    bool show_hitbox;
    bool show_player;
} player_skin_t;

typedef struct player_movement {
    v2f_t pos;
    v2f_t velocity;
    v2f_t destination;
    int speed;
    direction_t direction;
    chest_t *chest;
} player_movement_t;

typedef struct player player_t;

typedef struct player_fight {
    player_range_t range_type;
    unsigned int range;
    unsigned int attack_damage;
    float attack_speed;
    int projectile_speed;
    sfClock *attack_clock;
    sfClock *regen_clock;
    pname_t hited_by;
    player_t *target;
    uss_t kill_count;
    sfText *draw_kills;
    char *kills_str;
} player_fight_t;

typedef struct player {
    int id;
    pname_t name;
    player_stats_t stats;
    player_movement_t move;
    player_skin_t skin;
    player_fight_t fight;
    anim_t *anims;
    portal_t *portal;
} player_t;

typedef struct capy {
    map_id_t id_map;
    v2f_t pos;
} capy_t;

typedef struct npc {
    int id;
    capy_t capy[3];
    char is_here;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *anim_clock;
    sfIntRect anim_rect;
} npc_t;

void update_player(player_t *player, double dt, anim_props_t *anim_props,
bool **hitboxes);

void move_player(player_t *player, double dt, bool **hitboxes);
void attack_or_move(player_t *player, double dt, anim_props_t *anims_props,
bool **hitboxes);
void set_player_class(player_t *player, sfKeyCode key_code);
void set_player_direction(player_t *player);
void set_player_velocity(player_t *player, v2i_t mpos);
void animate_player(player_t *player);
int get_player_id(player_t *players[50], uss_t player_count,
pname_t player_name);
v2f_t calculate_velocity(v2f_t pos1, v2f_t pos2);
void move_player_ui(player_t *player);
bool update_player_portal(player_t *player);
npc_t *load_npc(void);
int mouse_on_player(player_t *me, player_t *player, v2i_t mpos);
void spawn_player(player_t *player, texture_list_t *textures);
void update_capy(npc_t *capy);
