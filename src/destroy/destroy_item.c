/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** destroy_item
*/

#include "item.h"
#include <stdlib.h>

void destroy_item(item_t *item)
{
    if (!item)
        return;
    free(item->description);
    destroy_text(item->text);
    sfTexture_destroy(item->texture);
    sfSprite_destroy(item->sprite);
    free(item);
}

void destroy_consos(conso_t *item)
{
    if (!item)
        return;
    free(item->description);
    destroy_text(item->text);
    sfTexture_destroy(item->texture);
    sfSprite_destroy(item->sprite);
    free(item);
}
