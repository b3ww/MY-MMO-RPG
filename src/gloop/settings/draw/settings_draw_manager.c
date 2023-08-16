/*
** EPITECH PROJECT, 2023
** src/gloop/settings/draw/settings_draw_manager
** File description:
** settings draw manager
*/

#include "rpg.h"

static void draw_settings_text(rpg_t *rpg)
{
    sfRenderWindow *wd = rpg->wd;
    scene_settings_t *settings = rpg->settings;

    sfRenderWindow_drawText(wd, settings->key_attack1->text->text, NULL);
    sfRenderWindow_drawText(wd, settings->key_attack2->text->text, NULL);
    sfRenderWindow_drawText(wd, settings->key_attack3->text->text, NULL);
    sfRenderWindow_drawText(wd, settings->key_attack4->text->text, NULL);
    sfRenderWindow_drawText(wd, settings->key_menu->text->text, NULL);
    sfRenderWindow_drawText(wd, settings->key_chat_open->text->text, NULL);
    sfRenderWindow_drawText(wd, settings->key_chat_close->text->text, NULL);
    sfRenderWindow_drawText(wd, settings->key_inventory->text->text, NULL);
    sfRenderWindow_drawText(wd, settings->key_quest->text->text, NULL);
    sfRenderWindow_drawText(wd, settings->title->text, NULL);
    sfRenderWindow_drawText(wd, settings->title_command->text, NULL);
}

void settings_draw_manager(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->wd, sfBlack);
    draw_background_lcher(rpg, rpg->launcher->background);
    sfRenderWindow_drawSprite(rpg->wd, rpg->settings->back->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->wd, rpg->settings->music->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->wd, rpg->settings->sound->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->wd, rpg->settings->cancel->sprite, NULL);
    draw_settings_text(rpg);
    sfRenderWindow_drawSprite(rpg->wd, rpg->cursor->sprite, NULL);
    sfRenderWindow_display(rpg->wd);
}
