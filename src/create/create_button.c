/*
** EPITECH PROJECT, 2023
** src/events/button
** File description:
** event button
*/

#include "button.h"
#include <stdlib.h>

void button_hover(button_t *button, sfMouseMoveEvent *move)
{
    sfFloatRect bound = sfSprite_getGlobalBounds(button->sprite);

    if (button->state == PRESSED)
        return;
    if (sfFloatRect_contains(&bound, move->x, move->y))
        button->state = HOVER;
    else
        button->state = NONE;
}

void button_pressed(button_t *button, sfMouseButtonEvent *evt)
{
    sfFloatRect bound = sfSprite_getGlobalBounds(button->sprite);

    if (evt->button == sfMouseLeft && ((button->state == HOVER &&
    sfFloatRect_contains(&bound, evt->x, evt->y))))
        button->state = PRESSED;
}

void button_released(button_t *button, sfMouseButtonEvent *evt)
{
    sfFloatRect bound = sfSprite_getGlobalBounds(button->sprite);

    if (evt->button == sfMouseLeft && button->state == PRESSED) {
        if (sfFloatRect_contains(&bound, evt->x, evt->y))
            button->state = RELEASED;
        else
            button->state = NONE;
    }
}

button_t *create_button(char const *texture, v2f_t pos, v2f_t scale,
sfIntRect *area)
{
    button_t *button = malloc(sizeof(button_t));

    button->texture = sfTexture_createFromFile(texture, area);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, pos);
    sfSprite_setScale(button->sprite, scale);
    button->state = NONE;
    button->is_hover = &button_hover;
    button->is_pressed = &button_pressed;
    button->is_released = &button_released;
    return button;
}
