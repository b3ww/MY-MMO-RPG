/*
** EPITECH PROJECT, 2023
** src/gloop/game/update/load_chest
** File description:
** load_chest
*/

#include "rpg.h"
#include "create.h"
#include "destroy.h"

static void feel_legendary_item(rpg_t *rpg, inventory_t *chest, int i)
{
    switch (rand() % 5) {
    case 0: chest->slots[i] = create_item_manager(rpg, "Balenciaga_Triple_S");
        return;
    case 1: chest->slots[i] = create_item_manager(rpg, "Lightsaber_bow");
        return;
    case 2: chest->slots[i] = create_item_manager(rpg, "Distortion_axe");
        return;
    case 3: chest->slots[i] = create_item_manager(rpg, "Gandalph_stick");
        return;
    case 4: chest->slots[i] = create_item_manager(rpg, "Napoleon_BonArmor");
        return;
    };

}

static void feel_epic_item(rpg_t *rpg, inventory_t *chest, int i, int rnd)
{
    if (rnd < 90) {
        switch (rand() % 5) {
        case 0: chest->slots[i] = create_item_manager(rpg, "Wool_slipper");
            return;
        case 1: chest->slots[i] = create_item_manager(rpg, "Lightning_bow");
            return;
        case 2: chest->slots[i] = create_item_manager(rpg, "Axeplosion");
            return;
        case 3: chest->slots[i] = create_item_manager(rpg, "Gem_stick");
            return;
        case 4: chest->slots[i] = create_item_manager(rpg, "Buzz_LightArmor");
            return;
        };
    }
    feel_legendary_item(rpg, chest, i);
}

static void feel_rare_item(rpg_t *rpg, inventory_t *chest, int i, int rnd)
{
    if (rnd < 70) {
        switch (rand() % 5) {
        case 0: chest->slots[i] = create_item_manager(rpg, "Running_shooes");
            return;
        case 1: chest->slots[i] = create_item_manager(rpg, "Happy_ending");
            return;
        case 2: chest->slots[i] = create_item_manager(rpg, "Wood_axe"); return;
        case 3: chest->slots[i] = create_item_manager(rpg, "Old_oak_stick");
            return;
        case 4: chest->slots[i] = create_item_manager(rpg, "Zodiac_Armor");
            return;
        };
    }
    feel_epic_item(rpg, chest, i, rnd);
}

static void feel_slots_random(rpg_t *rpg, inventory_t *chest, int i)
{
    int rnd = rand() % 100;

    if (rnd < 40) {
        switch (rand() % 5) {
        case 0: chest->slots[i] = create_item_manager(rpg, "Old_boots");
            return;
        case 1: chest->slots[i] = create_item_manager(rpg, "Jurassic_bow");
            return;
        case 2: chest->slots[i] = create_item_manager(rpg, "Rusty_axe");
            return;
        case 3: chest->slots[i] = create_item_manager(rpg, "Wood_stick");
            return;
        case 4: chest->slots[i] = create_item_manager(rpg, "Joker_armor");
            return;
        };
    }
    feel_rare_item(rpg, chest, i, rnd);
}

void load_chest(rpg_t *rpg, scene_game_t *game)
{
    game->chest->is_open = sfTrue;
    destroy_all_items(game->chest);
    for (int i = 0; i < 12; i++) {
        if (rand() % 5 == 0) {
            feel_slots_random(rpg, game->chest, i);
        } else
            game->chest->slots[i] = NULL;
    }
}
