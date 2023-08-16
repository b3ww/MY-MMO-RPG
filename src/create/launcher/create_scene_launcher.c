/*
** EPITECH PROJECT, 2023
** src/create/launcher/create_launcher
** File description:
** you're a bad developer
*/

#include "constants.h"
#include "scene_launcher.h"
#include <stdlib.h>

static void background_resize(launcher_background_t *bck)
{
    v2f_t size;

    size.x = WIDTH / sfSprite_getLocalBounds(bck->sprite_green).width;
    size.y = HEIGHT / sfSprite_getLocalBounds(bck->sprite_green).height * 1.1;
    sfSprite_setScale(bck->sprite_green, size);
    sfSprite_setPosition(bck->sprite_green, (v2f_t){0, -100});
    size.x = WIDTH / sfSprite_getLocalBounds(bck->sprite_red).width;
    size.y = HEIGHT / sfSprite_getLocalBounds(bck->sprite_red).height * 1.5;
    sfSprite_setScale(bck->sprite_red, size);
    sfSprite_setPosition(bck->sprite_red, (v2f_t){0, -300});
    size.x = WIDTH / sfSprite_getLocalBounds(bck->sprite_blue).width;
    size.y = HEIGHT / sfSprite_getLocalBounds(bck->sprite_blue).height;
    sfSprite_setScale(bck->sprite_blue, size);
}

static launcher_background_t create_lcher_background(void)
{
    launcher_background_t background;

    background.sprite_green = sfSprite_create();
    background.sprite_red = sfSprite_create();
    background.sprite_blue = sfSprite_create();
    background.texture_green = sfTexture_createFromFile(ASSET_BACKGROUND_GREEN,
        sfFalse);
    background.texture_red = sfTexture_createFromFile(ASSET_BACKGROUND_RED,
        sfFalse);
    background.texture_blue = sfTexture_createFromFile(ASSET_BACKGROUND_BLUE,
        sfFalse);
    sfSprite_setTexture(background.sprite_green, background.texture_green,
        sfFalse);
    sfSprite_setTexture(background.sprite_red, background.texture_red,
        sfFalse);
    sfSprite_setTexture(background.sprite_blue, background.texture_blue,
        sfFalse);
    background_resize(&background);
    return background;
}

static void create_launcher_button(scene_launcher_t *launcher)
{
    sfIntRect area_play = {PLAY_BUTTON_LINE_POS, SIZE_BUTTON_LINE};
    sfIntRect area_sett = {SETTINGS_BUTTON_LINE_POS, SIZE_BUTTON_LINE};
    sfIntRect area_donate = {DONATE_BUTTON_LINE_POS, SIZE_BUTTON_LINE};
    sfIntRect area_exit = {EXIT_BUTTON_LINE_POS, SIZE_BUTTON_LINE};
    sfIntRect area_right = {ARROW_RIGHT_POS, ARROW_SIZE_LINE};
    sfIntRect area_left = {ARROW_LEFT_POS, ARROW_SIZE_LINE};

    launcher->play = create_button(ASSET_BUTTON, (v2f_t){1475, 872},
        (v2f_t){6.75, 6.75}, &area_play);
    launcher->settings = create_button(ASSET_BUTTON,
        (v2f_t){1565, 770}, (v2f_t){3.5, 3.5}, &area_sett);
    launcher->donate = create_button(ASSET_BUTTON, (v2f_t){1630, 675},
    (v2f_t){3.35, 3.35}, &area_donate);
    launcher->exits = create_button(ASSET_BUTTON, (v2f_t){1690, 578},
        (v2f_t){3.25, 3.25}, &area_exit);
    launcher->bt_right = create_button(ASSET_LAUNCH_ARROW,
        (v2f_t){330, 880}, (v2f_t){3.25, 3.25}, &area_right);
    launcher->bt_left = create_button(ASSET_LAUNCH_ARROW,
        (v2f_t){230, 1080}, (v2f_t){3.25, 3.25}, &area_left);
}

void create_choice_team(scene_launcher_t *lch)
{
    lch->team.team_red = sfRectangleShape_create();
    lch->team.team_green = sfRectangleShape_create();
    lch->team.team_blue = sfRectangleShape_create();
    sfRectangleShape_move(lch->team.team_red, (v2f_t){155, 675});
    sfRectangleShape_move(lch->team.team_green, (v2f_t){225, 675});
    sfRectangleShape_move(lch->team.team_blue, (v2f_t){295, 675});
    sfRectangleShape_setSize(lch->team.team_red, (v2f_t){30, 30});
    sfRectangleShape_setSize(lch->team.team_green, (v2f_t){30, 30});
    sfRectangleShape_setSize(lch->team.team_blue, (v2f_t){30, 30});
    sfRectangleShape_setFillColor(lch->team.team_red, sfRed);
    sfRectangleShape_setFillColor(lch->team.team_green, sfGreen);
    sfRectangleShape_setFillColor(lch->team.team_blue, sfBlue);
    sfRectangleShape_setOutlineColor(lch->team.team_red, sfBlack);
    sfRectangleShape_setOutlineColor(lch->team.team_green, sfBlack);
    sfRectangleShape_setOutlineColor(lch->team.team_blue, sfBlack);
    sfRectangleShape_setOutlineThickness(lch->team.team_red, 2);
    sfRectangleShape_setOutlineThickness(lch->team.team_green, 2);
    sfRectangleShape_setOutlineThickness(lch->team.team_blue, 2);
}

scene_launcher_t *create_scene_launcher(void)
{
    scene_launcher_t *launcher = malloc(sizeof(scene_launcher_t));

    create_launcher_button(launcher);
    launcher->background = create_lcher_background();
    launcher->title = create_text("MY MMORPG!", 0, 185, (v2f_t){0, 0});
    sfText_setPosition(launcher->title->text, (v2f_t){WIDTH / 2 -
        sfText_getGlobalBounds(launcher->title->text).width / 2, 0});
    launcher->pseudo = create_text("Choose a pseudo...", 20, 40,
        (v2f_t){PSEUDO_POS});
    sfText_setColor(launcher->pseudo->text,
        sfColor_fromRGBA(255, 255, 255, 235));
    launcher->pseudo_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(launcher->pseudo_rect, (v2f_t){38, 980});
    sfRectangleShape_setSize(launcher->pseudo_rect, (v2f_t){380, 50});
    sfRectangleShape_setFillColor(launcher->pseudo_rect,
        sfColor_fromRGBA(0, 0, 0, 150));
    launcher->is_writing = sfFalse;
    create_choice_team(launcher);
    launcher->pseudo->str[0] = '\0';
    create_ip_port_input(launcher);
    return launcher;
}
