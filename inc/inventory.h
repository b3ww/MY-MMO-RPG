/*
** EPITECH PROJECT, 2023
** inc/inventory
** File description:
** inventory.h
*/

#pragma once

    #include "item.h"
    #include <SFML/Graphics.h>

    #define JUMP_NEXT_ITEM 64
    #define JUMP_NEXT_ITEM_Y 60
    #define INV_POS_BUTTON_X 803
    #define CHEST_POS_BUTTON_X 820
    #define INV_POS_BUTTON_ME_1 415
    #define INV_POS_BUTTON_ME_2 507
    #define INV_POS_BUTTON_ME_3 571
    #define CHEST_POS_BUTTON_Y 90
    #define INV_POS_BUTTON_PLAY_ITEM 108
    #define INV_POS_BUTTON_PLAY_2 205
    #define INV_POS_BUTTON_PLAY_3 267
    #define INV_SCALE 4, 4
    #define INV_POS 775 * 2, 355
    #define CHEST_POS 775 * 2, 50
    #define ASSET_PLAYER_INV "./assets/ui/inv_player.png"
    #define ASSET_CHEST_INV "./assets/ui/inv_chest.png"
    #define ASSET_TAKEN "./assets/ui/generic-rpg-ui-inventario01.png"
    #define ASSET_CHEST_GAME "./assets/objects/decorations/chest_game.png"

typedef enum item_type {
    UNCONSO,
    CONSO
}  item_type_t;

typedef union slot_u {
    item_t *unconso;
    conso_t *conso;
} slot_u_t;

typedef struct slot {
    item_type_t type;
    slot_u_t *slots;
} slot_t;

typedef struct inventory {
    inventory_type_t type;
    sfBool is_open;
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *slot_sp;
    sfTexture *slot_text;
    slot_t *slots[12];
} inventory_t;
