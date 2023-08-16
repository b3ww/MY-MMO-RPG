/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** rpg_particles
*/

#pragma once

    #include "particle.h"

typedef enum anim_type {
    DEFAULT,
    RAIN_ANIM,
    SPAWN_ANIM,
    ARROW_ANIM,
    GO_TO_ANIM,
    BIN_SMOKE_ANIM,
    SMOKE_ANIM
} anim_type_t;

anim_props_t *create_anim_props_rain(void);
anim_t *create_rain(anim_props_t *props);

anim_props_t *create_anim_props_smoke(void);
anim_t *create_smoke(anim_props_t *props);

anim_props_t *create_anim_props_splash_smoke(void);
anim_t *create_splash_smoke(anim_props_t *props);

void update_anims(anim_t **anims, double dt);
void end_smoke(anim_t *anim);
