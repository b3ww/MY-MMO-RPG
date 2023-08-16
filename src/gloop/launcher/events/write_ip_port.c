/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** write_ip_port
*/

#include "scene_launcher.h"
#include "tools.h"
#include "rpg.h"

void write_ip_port(scene_launcher_t *launcher, sfMouseButtonEvent evt)
{
    sfFloatRect bnd = sfRectangleShape_getGlobalBounds(launcher->ip_port_rect);

    if (sfFloatRect_contains(&bnd, evt.x, evt.y) == sfTrue) {
        launcher->ipwr = sfTrue;
        launcher->ip_port->str[my_strlen(launcher->ip_port->str) + 1] = '\0';
        if (!is_containing_char(launcher->ip_port->str, '|'))
            launcher->ip_port->str[my_strlen(launcher->ip_port->str)] = '|';
        sfText_setString(launcher->ip_port->text, launcher->ip_port->str);
    } else {
        launcher->ipwr = sfFalse;
        if (my_strlen(launcher->ip_port->str) > 1) {
            delete_char(launcher->ip_port->str, 0);
            sfText_setString(launcher->ip_port->text, launcher->ip_port->str);
        } else
            sfText_setString(launcher->ip_port->text, IP_PLACEHOLDER);
    }
}
