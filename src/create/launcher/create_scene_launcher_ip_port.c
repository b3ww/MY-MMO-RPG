/*
** EPITECH PROJECT, 2023
** src/create/launcher/create_launcher_ip_port
** File description:
** you're a bad developer
*/

#include "scene_launcher.h"
#include <stdlib.h>

void create_ip_port_input(scene_launcher_t *launcher)
{
    launcher->ip_port = create_text(IP_PLACEHOLDER, 30, 40, (v2f_t){740, 220});
    sfText_setColor(launcher->ip_port->text,
        sfColor_fromRGBA(225, 225, 225, 235));
    launcher->ip_port->str[0] = '\0';
    launcher->ip_port_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(launcher->ip_port_rect, (v2f_t){730, 222});
    sfRectangleShape_setSize(launcher->ip_port_rect, (v2f_t){500, 53});
    sfRectangleShape_setFillColor(launcher->ip_port_rect,
        sfColor_fromRGBA(0, 0, 0, 150));
    launcher->ipwr = sfFalse;
}
