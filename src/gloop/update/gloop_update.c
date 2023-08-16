/*
** EPITECH PROJECT, 2023
** 4_MyMMORPG
** File description:
** gloop_update
*/

#include "rpg.h"

static void set_mpos(rpg_t *rpg)
{
    v2i_t new_mpos = sfMouse_getPositionRenderWindow(rpg->wd);

    if (new_mpos.x > WIDTH) {
        rpg->mpos.x = WIDTH;
        if (rpg->full_screen)
            sfMouse_setPositionRenderWindow(rpg->mpos, rpg->wd);
    } else
        rpg->mpos.x = new_mpos.x;
    if (new_mpos.y > HEIGHT) {
        rpg->mpos.y = HEIGHT;
        if (rpg->full_screen)
            sfMouse_setPositionRenderWindow(rpg->mpos, rpg->wd);
    } else
        rpg->mpos.y = new_mpos.y;
}

static void set_essentials(rpg_t *rpg)
{
    get_delta_t(rpg);
    set_mpos(rpg);
    rpg->server_port = (uss_t)10001;
    rpg->mpos = sfMouse_getPositionRenderWindow(rpg->wd);
}

void gloop_update_manager(rpg_t *rpg)
{
    set_essentials(rpg);
    move_cursor(rpg->cursor, rpg->mpos);
}
