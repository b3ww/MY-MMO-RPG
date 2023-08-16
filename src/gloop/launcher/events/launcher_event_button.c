/*
** EPITECH PROJECT, 2023
** src/gloop/launcher/events/launcher_event_button
** File description:
** button event->manager
*/

#include "scene_launcher.h"
#include "tools.h"
#include "rpg.h"

static void change_team(player_t *player, scene_launcher_t *lch,
sfMouseButtonEvent evt)
{
    sfFloatRect bnd_r = sfRectangleShape_getGlobalBounds(lch->team.team_red);
    sfFloatRect bnd_g = sfRectangleShape_getGlobalBounds(lch->team.team_green);
    sfFloatRect bnd_b = sfRectangleShape_getGlobalBounds(lch->team.team_blue);

    if (sfFloatRect_contains(&bnd_r, evt.x, evt.y) == sfTrue)
        player->skin.color = RED;
    if (sfFloatRect_contains(&bnd_g, evt.x, evt.y) == sfTrue)
        player->skin.color = GREEN;
    if (sfFloatRect_contains(&bnd_b, evt.x, evt.y) == sfTrue)
        player->skin.color = BLUE;
    reload_player_skin(player);
}

void launcher_button_pressed(scene_launcher_t *launcher,
sfMouseButtonEvent evt)
{
    launcher->play->is_pressed(launcher->play, &evt);
    launcher->exits->is_pressed(launcher->exits, &evt);
    launcher->donate->is_pressed(launcher->donate, &evt);
    launcher->settings->is_pressed(launcher->settings, &evt);
    launcher->bt_right->is_pressed(launcher->bt_right, &evt);
    launcher->bt_left->is_pressed(launcher->bt_left, &evt);
}

static void write_pseudo(scene_launcher_t *launcher, sfMouseButtonEvent evt)
{
    sfFloatRect bnd = sfRectangleShape_getGlobalBounds(launcher->pseudo_rect);

    if (sfFloatRect_contains(&bnd, evt.x, evt.y) == sfTrue) {
        launcher->is_writing = sfTrue;
        launcher->pseudo->str[my_strlen(launcher->pseudo->str) + 1] = '\0';
        if (!is_containing_char(launcher->pseudo->str, '|'))
            launcher->pseudo->str[my_strlen(launcher->pseudo->str)] = '|';
        sfText_setString(launcher->pseudo->text, launcher->pseudo->str);
    } else {
        launcher->is_writing = sfFalse;
        if (my_strlen(launcher->pseudo->str) > 1) {
            delete_char(launcher->pseudo->str, 0);
            sfText_setString(launcher->pseudo->text, launcher->pseudo->str);
        } else
            sfText_setString(launcher->pseudo->text, "Choose a pseudo...");
    }
}

void launcher_button_released(player_t *player, scene_launcher_t *launcher,
sfMouseButtonEvent evt)
{
    launcher->play->is_released(launcher->play, &evt);
    launcher->donate->is_released(launcher->donate, &evt);
    launcher->exits->is_released(launcher->exits, &evt);
    launcher->settings->is_released(launcher->settings, &evt);
    launcher->bt_right->is_released(launcher->bt_right, &evt);
    launcher->bt_left->is_released(launcher->bt_left, &evt);
    write_pseudo(launcher, evt);
    write_ip_port(launcher, evt);
    change_team(player, launcher, evt);
}

void launcher_button_hover(scene_launcher_t *launcher, sfMouseMoveEvent evt)
{
    launcher->donate->is_hover(launcher->donate, &evt);
    launcher->play->is_hover(launcher->play, &evt);
    launcher->exits->is_hover(launcher->exits, &evt);
    launcher->settings->is_hover(launcher->settings, &evt);
    launcher->bt_right->is_hover(launcher->bt_right, &evt);
    launcher->bt_left->is_hover(launcher->bt_left, &evt);
}
