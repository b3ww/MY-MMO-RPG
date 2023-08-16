/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** destroy_button
*/

#include "button.h"
#include "destroy.h"

void destroy_button(button_t *button)
{
    sfTexture_destroy(button->texture);
    sfSprite_destroy(button->sprite);
    free(button);
}
