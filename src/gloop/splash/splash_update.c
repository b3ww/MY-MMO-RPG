/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** splash_update
*/

#include "rpg.h"
#include "destroy.h"
#include "rpg_particles.h"

static void animate_background(splash_t *splash)
{
    if (GET_CLOCK_SEC(splash->anim_clock) > 0.2) {
        sfClock_restart(splash->anim_clock);
        splash->anim_rect.left += 498;
        if (splash->anim_rect.left > 498 * 5)
            splash->anim_rect.left = 0;
        sfSprite_setTextureRect(splash->sprite, splash->anim_rect);
    }
    if (splash->background_alpha < 250)
        splash->background_alpha += 4;
    if (splash->background_alpha > 254)
        splash->background_alpha = 254;
    sfSprite_setColor(splash->sprite, sfColor_fromRGBA(255, 255, 255,
        splash->background_alpha));
}

void splash_update(rpg_t *rpg)
{
    update_anims(&rpg->anims, rpg->dt);
    animate_background(rpg->splash);
    if (GET_CLOCK_SEC(rpg->splash->splash_clock) > 3) {
        if (rpg->anims != NULL)
            anim_destroy(rpg->anims);
        rpg->anims = NULL;
        rpg->scene = LAUNCHER;
        destroy_splash(rpg->splash);
        rpg->splash = NULL;
    }
}
