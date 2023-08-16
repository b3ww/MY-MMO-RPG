/*
** EPITECH PROJECT, 2023
** inc/item
** File description:
** intem.h
*/

#pragma once

    #include <SFML/Graphics.h>
    #include "text.h"

    #define INVTXT_POS 0, 0

typedef enum inventory_type {
    ME,
    CHEST,
    PLAYER
} inventory_type_t;

typedef enum rarity {
    COMMUN,
    RARE,
    EPIC,
    LENGEDARY
} rarity_t;

typedef enum state_item {
    IS_HOVER,
    IS_PRESSED,
    IS_RELEASED,
    IS_NONE
} state_item_t;

typedef struct item {
    rarity_t rarity;
    state_item_t state;
    char old_slot;
    inventory_type_t old_place;
    char name[20];
    char *description;
    text_t *text;
    sfTexture *texture;
    sfSprite *sprite;
    struct {
        int attack;
        int attack_speed;
        int range;
        int health;
        int speed;
    };
} item_t;

typedef struct conso {
    char name[20];
    char *description;
    char old_slot;
    inventory_type_t old_place;
    state_item_t state;
    text_t *text;
    sfTexture *texture;
    sfSprite *sprite;
    struct {
        int heal;
        int mana;
    };
} conso_t;

    #define BOOTS(index) index >= 0 && index <= 4 ? true : false
    #define WEAPON(index) index >= 5 && index <= 16 ? true : false
    #define ARMOR(index) index >= 17 && index <= 20 ? true : false
