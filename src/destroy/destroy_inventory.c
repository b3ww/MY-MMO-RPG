/*
** EPITECH PROJECT, 2023
** src/destroy/destroy_inventory
** File description:
** destroy inventory
*/

#include "inventory.h"
#include "destroy.h"

void destroy_slot(slot_t *slot)
{
    if (!slot)
        return;
    if (slot->type == UNCONSO) {
        destroy_item(slot->slots->unconso);
    } else {
        destroy_consos(slot->slots->conso);
    }
    free(slot->slots);
    free(slot);
}

void destroy_all_items(inventory_t *inv)
{
    for (int i = 0; i < 12; i++)
        destroy_slot(inv->slots[i]);
}

void destroy_inventory(inventory_t *inv)
{
    destroy_all_items(inv);
    sfSprite_destroy(inv->slot_sp);
    sfTexture_destroy(inv->slot_text);
    sfSprite_destroy(inv->sprite);
    sfTexture_destroy(inv->texture);
    free(inv);
}
