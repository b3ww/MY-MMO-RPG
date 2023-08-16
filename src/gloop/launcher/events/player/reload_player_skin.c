/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** reload_player_texture
*/

#include "rpg.h"
#include "tools.h"
#include <stdlib.h>

static char *create_skin_path(char *pclass, char *color)
{
    char *skin_path = malloc(sizeof(char) * 50);

    skin_path[0] = '\0';
    my_strcat(skin_path, "assets/entity/player/");
    my_strcat(skin_path, pclass);
    my_strcat(skin_path, "_");
    my_strcat(skin_path, color);
    my_strcat(skin_path, ".png");

    return skin_path;
}

static char *get_color_str(player_color_t color)
{
    switch (color) {
    case RED: return "red";
    case GREEN: return "green";
    case BLUE: return "blue";
    default:
        return NULL;
    }
}

void reload_player_skin(player_t *player)
{
    char *skin_path;
    sfFloatRect bounds;

    if (player->skin.texture != NULL)
        sfTexture_destroy(player->skin.texture);
    skin_path = create_skin_path(get_pclass_str(player->skin.pclass),
        get_color_str(player->skin.color));
    player->skin.texture = sfTexture_createFromFile(skin_path, NULL);
    sfSprite_setTexture(player->skin.sprite, player->skin.texture, sfFalse);
    sfSprite_setTextureRect(player->skin.sprite, player->skin.anim_rect);
    sfSprite_setScale(player->skin.sprite, player->skin.scale);
    sfSprite_setOrigin(player->skin.sprite, (v2f_t){16, 16});
    bounds = sfSprite_getGlobalBounds(player->skin.sprite);
    sfRectangleShape_setSize(player->skin.hitbox, (v2f_t){bounds.width / 2,
        bounds.height / 2});
    sfRectangleShape_setOrigin(player->skin.hitbox, (v2f_t){bounds.width / 4,
        bounds.height / 4});

    free(skin_path);
}
