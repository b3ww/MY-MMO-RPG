/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** anim_arrow
*/

#include "rpg_particles.h"
#include "tools.h"
#include <stdlib.h>
#include "fight.h"

static shape_t *start(sfSprite *attacker)
{
    shape_t *shape = malloc(sizeof(shape_t));

    shape->type = SPRITE_CENTER;
    shape->body.sprite = attacker;
    shape->is_default = false;
    return shape;
}

static shape_t *end(sfSprite *victim)
{
    shape_t *shape = malloc(sizeof(shape_t));

    shape->type = SPRITE_CENTER;
    shape->body.sprite = victim;
    shape->is_default = false;
    return shape;
}

static shape_t *part(sfTexture *texture)
{
    shape_t *shape = malloc(sizeof(shape_t));
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, false);
    shape->type = SPRITE;
    shape->body.sprite = sprite;
    shape->is_default = false;
    return shape;
}

anim_props_t *create_anim_props_arrow(sfTexture *texture)
{
    anim_props_t *props = create_anim_props(ARROW_ANIM, part(texture), NULL,
        NULL);

    props->follow_dest = true;
    props->part_texture = texture;
    return props;
}

anim_t *create_arrow_anim(anim_props_t *props, attack_data_t *attack)
{
    anim_t *anim = anim_create();

    set_anim_props(anim, props);
    anim_set_shape_start(anim, start(attack->attacker->skin.sprite));
    anim_set_shape_end(anim, end(attack->victim->skin.sprite));
    anim_set_frequency(anim, attack->attacker->fight.attack_speed);
    anim_set_batch_size(anim, 1);
    anim_set_duration(anim, -1);
    anim_set_speed(anim, attack->attacker->fight.projectile_speed);
    anim_set_scale(anim, (v2f_t){2.3, 2.3});
    anim->rotation = 45;
    anim_set_color(anim, sfColor_fromRGBA(200, 30, 30, 180));
    anim->at_death = &player_send_attack_particle;
    anim->at_death_data = (void *)attack;
    anim->data_to_free = true;
    return anim;
}
