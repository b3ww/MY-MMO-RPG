/*
** EPITECH PROJECT, 2023
** src/create/create_chest
** File description:
** create chest
*/

#include "scene_game.h"
#include <stdlib.h>

chest_t *create_chest(chest_t *list, v2f_t pos)
{
    chest_t *ele = malloc(sizeof(chest_t));

    ele->texture = sfTexture_createFromFile(ASSET_CHEST_GAME, NULL);
    ele->sprite = sfSprite_create();
    sfSprite_setTexture(ele->sprite, ele->texture, sfFalse);
    sfSprite_setPosition(ele->sprite, pos);
    sfSprite_setScale(ele->sprite, (v2f_t){1, 1});
    sfSprite_setTextureRect(ele->sprite, (sfIntRect){0, 0, 54, 50});
    ele->visited = sfFalse;
    ele->next = list;
    return ele;
}
