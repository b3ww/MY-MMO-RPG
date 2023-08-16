/*
** EPITECH PROJECT, 2023
** 4_MyMMORPG
** File description:
** launcher_draw_manager
*/

#include "rpg.h"

static void draw_button(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->wd, rpg->launcher->donate->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->wd, rpg->launcher->play->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->wd, rpg->launcher->settings->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->wd, rpg->launcher->exits->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->wd, rpg->launcher->bt_right->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->wd, rpg->launcher->bt_left->sprite, NULL);
    sfSprite_setPosition(rpg->launcher->bt_left->sprite, (v2f_t){25, 880});
}

static void draw_texts(rpg_t *rpg)
{
    sfRenderWindow_drawText(rpg->wd, rpg->launcher->title->text, NULL);
    sfRenderWindow_drawText(rpg->wd, rpg->launcher->pseudo->text, NULL);
    sfRenderWindow_drawText(rpg->wd, rpg->launcher->ip_port->text, NULL);
}

static void draw_player(rpg_t *rpg, sfSprite *skin)
{
    sfSprite_setScale(skin, (v2f_t){15, 15});
    sfRenderWindow_drawSprite(rpg->wd, skin, NULL);
    sfSprite_setScale(skin, (v2f_t){1, 1});
}

void draw_background_lcher(rpg_t *rpg, launcher_background_t bck)
{
    switch (rpg->players[0]->skin.color) {
        case GREEN: sfRenderWindow_drawSprite(rpg->wd, bck.sprite_green, NULL);
            break;
        case RED: sfRenderWindow_drawSprite(rpg->wd, bck.sprite_red, NULL);
            break;
        case BLUE: sfRenderWindow_drawSprite(rpg->wd, bck.sprite_blue, NULL);
            break;
    }
}

void launcher_draw_manager(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->wd, sfBlack);
    sfRenderWindow_setView(rpg->wd, rpg->view);
    draw_background_lcher(rpg, rpg->launcher->background);
    draw_button(rpg);
    sfRenderWindow_drawRectangleShape(rpg->wd, rpg->launcher->pseudo_rect,
        NULL);
    sfRenderWindow_drawRectangleShape(rpg->wd, rpg->launcher->ip_port_rect,
        NULL);
    sfRenderWindow_drawRectangleShape(rpg->wd, rpg->launcher->team.team_red,
        NULL);
    sfRenderWindow_drawRectangleShape(rpg->wd, rpg->launcher->team.team_blue,
        NULL);
    sfRenderWindow_drawRectangleShape(rpg->wd, rpg->launcher->team.team_green,
        NULL);
    draw_texts(rpg);
    draw_player(rpg, rpg->players[0]->skin.sprite);
    sfRenderWindow_drawSprite(rpg->wd, rpg->cursor->sprite, NULL);
    sfRenderWindow_display(rpg->wd);
}
