/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** splash_draw
*/

#include "rpg.h"
#include "game_draw.h"

void splash_draw(rpg_t *rpg)
{
    if (rpg->splash == NULL)
        return;
    sfRenderWindow_clear(rpg->wd, sfBlack);
    sfRenderWindow_drawSprite(rpg->wd, rpg->splash->sprite, NULL);
    draw_particles(rpg->wd, rpg->anims);
    sfRenderWindow_display(rpg->wd);
}
