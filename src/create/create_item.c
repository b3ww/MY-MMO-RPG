/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** create_item
*/

#include "item.h"
#include "wcsv.h"
#include "tools.h"
#include "rpg.h"

static char *edit_description(char *str)
{
    for (int i = 0; str[i]; i++) {
        switch (str[i]) {
            case '_': str[i] = ' '; break;
            case '\'': str[i] = ','; break;
            case '+': str[i] = '\n'; break;
            default: break;
        }
    }
    return str;
}

static void set_stats(item_t *item, char *name, char **all, rpg_t *rpg)
{
    int index = 0;
    char **infos;

    for (; all[index]; index++) {
        if (!my_strcmp(name, all[index]))
            break;
    }
    infos = rpg->file_config.stats->content[index + 1];
    item->attack = my_getnbr(infos[1]);
    item->attack_speed = my_getnbr(infos[2]);
    item->range = my_getnbr(infos[3]);
    item->health = my_getnbr(infos[4]);
    item->speed = my_getnbr(infos[5]);
}

item_t *create_item(rpg_t *rpg, char *name)
{
    wcsv_t *csv = rpg->file_config.items;
    char **line = NULL;
    item_t *ret;
    char **tmp = NULL;

    if (!(line = wcsv_get(csv, (wreq_t){name, VALUE, NULL, LINE})))
        return NULL;
    ret = malloc(sizeof(item_t));
    ret->state = IS_NONE;
    my_strcpy(ret->name, line[0]);
    ret->description = my_strdup(edit_description(line[1]));
    ret->rarity = my_getnbr(line[2]);
    ret->texture = sfTexture_createFromFile(line[3], NULL);
    ret->sprite = sfSprite_create();
    sfSprite_setTexture(ret->sprite, ret->texture, 0);
    ret->text = create_text(ret->description, 200, 5, (v2f_t){INVTXT_POS});
    tmp = wcsv_get(csv, (wreq_t){name, VALUE, NULL, COLUMN});
    set_stats(ret, name, tmp, rpg);
    free(tmp);
    return ret;
}

conso_t *create_conso(rpg_t *rpg, char *name)
{
    wcsv_t *csv = rpg->file_config.consos;
    char **line = NULL;
    conso_t *ret = NULL;

    if (!(line = wcsv_get(csv, (wreq_t){name, VALUE, NULL, LINE})))
        return NULL;
    ret = malloc(sizeof(conso_t));
    my_strcpy(ret->name, line[0]);
    ret->description = my_strdup(edit_description(line[1]));
    ret->texture = sfTexture_createFromFile(line[3], NULL);
    ret->sprite = sfSprite_create();
    sfSprite_setTexture(ret->sprite, ret->texture, 0);
    ret->text = create_text(ret->description, 200, 5, (v2f_t){INVTXT_POS});
    ret->heal = (!my_strcmp(name, "Health_potion") ||
        !my_strcmp(name, "Strawberry")) ? my_getnbr(line[2]) : 0;
    ret->mana = (!my_strcmp(name, "Health_potion") ||
        !my_strcmp(name, "Strawberry")) ? 0 : my_getnbr(line[2]);
    return ret;
}
