/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** manage_mouse_npc
*/

/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** mouse_pressed_npc
*/

#include "struct.h"
#include "chat.h"

void mouse_pressed_npc(rpg_t *rpg, sfEvent evt)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(rpg->npc->sprite);
    int tmp = 0;

    for (int i = 0; i < 3; i++)
        if (rpg->npc->capy[i].id_map == rpg->map->id)
            tmp = 1;
    if (tmp == 0)
        return;
    sfSprite_setPosition(rpg->npc->sprite, rpg->npc->capy[(int) rpg->map->id
    / 2].pos);
    if (sfFloatRect_contains(&rect, evt.mouseButton.x, evt.mouseButton.y)) {
        add_to_chat(rpg->chat, NAME_NPC);
        add_to_chat(rpg->chat, TEXT_NPC1);
        add_to_chat(rpg->chat, TEXT_NPC2);
        add_to_chat(rpg->chat, TEXT_NPC3);
        add_to_chat(rpg->chat, TEXT_NPC4);
        add_to_chat(rpg->chat, TEXT_NPC5);
        add_to_chat(rpg->chat, TEXT_NPC6);
    }
}
