/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** stack
*/

#include "map.h"
#include "textures.h"
#include "constants.h"
#include "create.h"
#include "wcsv.h"
#include "tools.h"

static portal_t *load_new_portal(texture_list_t *textures, char **line_tmp,
int id)
{
    portal_t *portal = create_portal(get_texture_from_id(textures,
        GREEN_PORTAL_ID));
    portal->map_dest_id = my_getnbr(line_tmp[0]);
    portal->id = id;
    portal->map_dest_spawn_pos = (v2f_t){my_getnbr(line_tmp[1]) * TILE_WIDTH,
        my_getnbr(line_tmp[2]) * TILE_HEIGHT};
    return portal;
}

void stack_portals(map_t *to_stack, char **to_parse,
texture_list_t *textures)
{
    char **line_tmp = NULL;
    char **pos = to_parse + 13;

    to_stack->portals = NULL;
    for (int i = 0; i < 4; i++) {
        line_tmp = wstr_to_word_array(to_parse[i], " ");
        if (TABSIZE(line_tmp) != 3) {
            TABFREE(line_tmp);
            continue;
        }
        append_portal(&to_stack->portals, load_new_portal(textures, line_tmp,
            i));
        TABFREE(line_tmp);
    }
    for (int i = 0; pos[i]; i++) {
        for (int j = 0; pos[i][j]; j++)
            pos[i][j] >= 'a' && pos[i][j] <= 'd' ?
            set_portal_pos(to_stack->portals, pos[i][j], i, j) : 0;
    }
}

bool stack_hitbox(map_t *to_stack, char **to_parse, v2f_t size)
{
    to_stack->hitboxes = malloc(sizeof(bool *) * (size.y + 1));
    to_stack->hitboxes[(int)size.y] = NULL;
    for (int i = 0; i < size.y; i++) {
        to_stack->hitboxes[i] = malloc(sizeof(bool) * size.x);
        for (int j = 0; to_parse[i][j]; j++)
            to_stack->hitboxes[i][j] = to_parse[i][j] == 'o' ? false : true;
    }
    return true;
}

entity_t *entitie(int i, int j, char code, rpg_t *rpg)
{
    entity_t *ret = malloc(sizeof(entity_t));
    ret->upper = code == 'l' || code == 'B' ? false : true;
    ret->sprite = sfSprite_create();
    ret->position = (v2f_t){j * TILE_WIDTH, i * TILE_HEIGHT};
    sfSprite_setTexture(ret->sprite, get_texture_from_id(rpg->textures,
    get_texture_id(code)), sfFalse);
    sfSprite_setPosition(ret->sprite, (v2f_t){(j * TILE_WIDTH), (i *
        TILE_HEIGHT)});
    if (code == 't' || code == 'T' || code == 'v') {
        sfSprite_setScale(ret->sprite, (v2f_t){2.1, 1.23 * 2.f});
        return ret;
    } if (code == 'M' || code == 'm' || code == 'q') {
        sfSprite_setScale(ret->sprite, (v2f_t){4.11, 4.7});
        return ret;
    } if (code == 'l' || code == 'B') {
        sfSprite_setScale(ret->sprite, (v2f_t){3.36, 3.78});
        return ret;
    }
    sfSprite_setScale(ret->sprite, (v2f_t){2, 2});
    return ret;
}

bool stack_entities(map_t *to_stack, char **to_parse, v2f_t size,
rpg_t *rpg)
{
    int e_size = 0;

    for (int i = 0; i < size.y; i++) {
        for (int j = 0; j < size.x; j++)
            e_size += to_parse[i][j] == 'o' || to_parse[i][j] == 'p'
            || to_parse[i][j] == 'P' || (to_parse[i][j] >= 'a' &&
            to_parse[i][j] <= 'e') ? 0 : 1;
    }
    to_stack->entities = malloc(sizeof(entity_t *) * (e_size + 1));
    to_stack->entities[e_size] = NULL;
    to_stack->entities[0] = NULL;
    e_size = 0;
    for (int i = 0; i < size.y; i++) {
        for (int j = 0; j < size.x; j++)
            (to_parse[i][j] != 'o' && to_parse[i][j] != 'p'
            && to_parse[i][j] != 'P' && !(to_parse[i][j] >= 'a' &&
            to_parse[i][j] <= 'e')) ? (to_stack->entities[e_size++] =
            entitie(i, j, to_parse[i][j], rpg)) : 0;
    }
    return true;
}
