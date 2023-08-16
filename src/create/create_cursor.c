/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** create_cursor
*/

#include "cursor.h"
#include "create.h"

cursor_t *create_cursor(void)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    cursor->sprite = sfSprite_create();
    cursor->textures[ARROW] = sfTexture_createFromFile(ASSET_CURSOR_ARROW,
        NULL);
    cursor->hotspots[ARROW] = (v2f_t){2, 1};
    cursor->textures[SELECT] = sfTexture_createFromFile(ASSET_CURSOR_SELECT,
        NULL);
    cursor->hotspots[SELECT] = (v2f_t){7, 1};
    cursor->textures[SELECT_TAP] = sfTexture_createFromFile(
        ASSET_CURSOR_SELECT_TAP, NULL);
    cursor->hotspots[SELECT_TAP] = (v2f_t){7, 1};
    cursor->type = SELECT;
    cursor->drag = NULL;
    sfSprite_setTexture(cursor->sprite, cursor->textures[SELECT], sfFalse);
    return cursor;
}
