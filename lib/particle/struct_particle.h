/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** struct_particle
*/

#pragma once

    #include "shortcut.h"

typedef enum shape_type {
    RECT,
    RECT_OUTLINE,
    CIRCLE,
    CIRCLE_OUTLINE,
    SPRITE,
    SPRITE_CENTER,
    MIRROR
} shape_type_t;

typedef union shape_union {
    sfRectangleShape *rect;
    sfCircleShape *circle;
    sfSprite *sprite;
    v2f_t offset;
} shape_union_t;

typedef struct shape {
    shape_type_t type;
    shape_union_t body;
    bool is_default;
} shape_t;

typedef struct scale {
    v2f_t scale_modifier;
    v2f_t scale_min;
    v2f_t scale_max;
} scale_t;

typedef struct anim_props {
    int type;
    shape_t *shape_part;
    shape_t *shape_start;
    shape_t *shape_end;
    bool follow_dest;
    sfTexture *part_texture;
    struct anim_props *next;
} anim_props_t;

typedef struct anim anim_t;

typedef struct particles {
    shape_type_t shape_type;
    shape_union_t shape;
    v2f_t position;
    v2f_t destination;
    v2f_t move;
    short speed;
    scale_t *scale_props;
    float rotation_modifier;
    sfColor color;
    double time_elapsed;
    bool arrived;
    anim_t *anim;
    struct particles *next;
} particles_t;

// @brief Here's all of the default values for this struct :
// @param shape_part Rectangle 1:1:1:1
// @param shape_start Rectangle_outline 100:100:100:100
// @param shape_end Rectangle 145:145:10:10
// @param speed 1 (pixels/seconds)
// @param frequency 10 (per seconds)
// @param duration 2 (seconds)
// @param scale 1
// @param scale_modifier 1 (no negative, shrink < 1, grow > 1)
// @param rotation 0
// @param color {255, 0, 0, 150}
typedef struct anim {
    int id;
    particles_t *particles;

    shape_t *shape_part;
    shape_t *shape_start;
    shape_t *shape_end;

    bool show_zones;
    bool follow_destination;
    int speed;
    double spawn_delay_value;
    double spawn_delay;
    unsigned int batch_size;
    float duration;
    double time_elapsed;
    v2f_t scale;
    scale_t *scale_props;
    float rotation;
    float rotation_modifier;
    sfColor color;
    bool is_generating;
    void (*at_death)(void *);
    void *at_death_data;
    bool data_to_free;
    struct anim *next;
    struct anim *previous;
} anim_t;
