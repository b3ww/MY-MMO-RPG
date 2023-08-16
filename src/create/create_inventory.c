/*
** EPITECH PROJECT, 2023
** src/create/create_inventory
** File description:
** create inventory
*/

#include "inventory.h"
#include "create.h"
#include "rpg.h"
#include <stdlib.h>

slot_t *create_item_manager(rpg_t *rpg, char *name)
{
    slot_t *slots = malloc(sizeof(slot_t));

    slots->type = UNCONSO;
    slots->slots = malloc(sizeof(slot_u_t));
    slots->slots->unconso = create_item(rpg, name);
    if (!slots->slots->unconso) {
        free(slots->slots);
        return NULL;
    }
    sfSprite_setScale(slots->slots->unconso->sprite, (v2f_t){INV_SCALE});
    return slots;
}

static void fill_inventory(inventory_t *inv)
{
    for (int i = 0; i < 12; i++)
        inv->slots[i] = NULL;
}

inventory_t *create_inventory(char load)
{
    inventory_t *inv = malloc(sizeof(inventory_t));

    inv->texture = (load == 1) ? sfTexture_createFromFile(ASSET_CHEST_INV,
        NULL) : sfTexture_createFromFile(ASSET_PLAYER_INV, NULL);
    inv->is_open = sfFalse;
    inv->sprite = sfSprite_create();
    inv->slot_text = sfTexture_createFromFile(ASSET_TAKEN, sfFalse);
    inv->slot_sp = sfSprite_create();
    sfSprite_setTexture(inv->slot_sp, inv->slot_text, sfFalse);
    sfSprite_setScale(inv->slot_sp, (v2f_t){INV_SCALE});
    sfSprite_setTexture(inv->sprite, inv->texture, sfFalse);
    sfSprite_setScale(inv->sprite, (v2f_t){INV_SCALE});
    (load == 0) ? sfSprite_setPosition(inv->sprite, (v2f_t){INV_POS}) :
        sfSprite_setPosition(inv->sprite, (v2f_t){CHEST_POS});
    fill_inventory(inv);
    return inv;
}
