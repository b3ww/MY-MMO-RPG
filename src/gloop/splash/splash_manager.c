/*
** EPITECH PROJECT, 2023
** 4_MyMMORPG
** File description:
** splash_manager
*/

#include "rpg.h"

static void splash_event(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->wd, &event))
        gloop_event(rpg, event);
}

void splash_manager(rpg_t *rpg)
{
    splash_event(rpg);
    splash_update(rpg);
    splash_draw(rpg);
}
