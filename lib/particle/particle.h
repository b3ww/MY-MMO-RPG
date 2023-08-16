/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** particle
*/

#pragma once

/*-------------------------------INCLUDE-------------------------------------*/

    #include <SFML/Graphics.h>
    #include "struct_particle.h"
    #include "constants.h"

    #define ANIM_SPEED 1
    #define ANIM_FREQUENCY 2
    #define ANIM_DURATION 5
    #define ANIM_COLOR 255, 0, 0, 150
    #define ANIM_SCALE 1, 1
    #define ANIM_BATCH_SIZE 1
    #define PARTICLE_POS 0, 0
    #define PARTICLE_SIZE 25, 25
    #define SHAPE_START 0, 0
    #define SHAPE_END 0, 200
    #define SHAPE_SIZE 100, 100

/*------------------------------PROGRAMME------------------------------------*/

anim_t *anim_create(void);
void anim_append(anim_t **anim_list, anim_t *new_anim);
void anim_update(anim_t *animation, double dt);
void anim_draw(sfRenderWindow *win, anim_t *animation);
int is_anim_ended(anim_t *anim);
void anim_destroy(anim_t *anim);
void anim_destroy_secure(anim_t **anim_list, anim_t *anim);

void anim_set_id(anim_t *anim, int id);
void anim_set_shape_part(anim_t *anim, shape_t *shape_part);
void anim_set_shape_start(anim_t *anim, shape_t *shape_start);
void anim_set_shape_end(anim_t *anim, shape_t *shape_end);
void anim_set_speed(anim_t *anim, int speed);
void anim_set_frequency(anim_t *anim, float frequency);
void anim_set_batch_size(anim_t *anim, unsigned int batch_size);
void anim_set_duration(anim_t *anim, float duration);
void anim_set_scale(anim_t *anim, sfVector2f scale);
void anim_set_scale_modifier(anim_t *anim, v2f_t scale_modifier,
sfVector2f scale_min, sfVector2f scale_max);
void anim_set_is_generating(anim_t *anim, bool is_generating);
void anim_set_rotation(anim_t *anim, float rotation);
void anim_set_color(anim_t *anim, sfColor color);
void anim_set_rgb(anim_t *anim);

particles_t *particle_create(anim_t *anim);
void set_shape_part(particles_t *part, anim_t *anim);
v2f_t set_particle_movement(v2f_t spawn_pos, v2f_t dest);
void set_destination(particles_t *part, anim_t *anim);
int particles_move_or_ended(particles_t *part, double dt);
int particle_update(particles_t *particle, double dt);
v2f_t get_from_rect(sfFloatRect bounds);
v2f_t get_from_circle(sfCircleShape *circle);
v2f_t get_pos_from_circle_outline(sfCircleShape *circle);
v2f_t get_random_pos(shape_t *shape);
v2f_t get_sprite_center(sfSprite *sprite);
void particle_destroy(particles_t *particle);

void append_anim_props(anim_props_t **anim_props, anim_props_t *to_add);
anim_props_t *create_anim_props(int type, shape_t *shape_part,
shape_t *shape_start, shape_t *shape_end);
void set_anim_props(anim_t *anim, anim_props_t *props);
anim_props_t *get_anims_props(anim_props_t *anims_props, int id);

void destroy_shape(shape_t *shape);
void destroy_shape_part(shape_type_t shape_type, shape_union_t shape);
void destroy_particles(particles_t *particle);
void destroy_anims_props(anim_props_t *anims_props);
void destroy_anims(anim_t *anim);

v2f_t float_multiply_v2f(v2f_t v, float x);
v2f_t add_two_v2f_part(v2f_t v1, v2f_t v2);
float vector_norm(v2f_t vector);
double get_delta_time(sfClock *game_clock, double *prev_frame_time);
int get_random_nb_between(int from, int min, int max, int epsilon);
int contain_v2f(v2f_t min, v2f_t max, v2f_t ele);
void destroy_scale(scale_t *scale);
void set_rotation(shape_type_t shape_type, shape_union_t shape,
float rotation);
void rotate(shape_type_t shape_type, shape_union_t shape, float rotation);
