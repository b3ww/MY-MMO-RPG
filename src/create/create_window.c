/*
** EPITECH PROJECT, 2023
** 4_MyMMORPG
** File description:
** create_window
*/

#include "rpg.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode video_mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode, "MY MMO RPG",
        sfFullscreen, NULL);
    return window;
}
