/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** chat
*/

#pragma once

    #include <SFML/Graphics.h>

    #define NAME_NPC "CAPY:"
    #define QUEST_NPC "QUESTS:"
    #define QUEST_NPC1 "Battre 10 ennemis "
    #define QUEST_NPC2 "Recuperer votre arme legendaire "
    #define QUEST_NPC3 "Visiter toute les map"
    #define TEXT_NPC1 "Bienvenue dans notre monde fantastique, ou trois"
    #define TEXT_NPC2 "equipes s'affrontent pour la victoire. Votre mission"
    #define TEXT_NPC3 "est de vaincre les deux autres equipes, en gagnant"
    #define TEXT_NPC4 "des points supplementaires en eliminant des ennemis"
    #define TEXT_NPC5 "dans leur camp. Cooperez avec vos allies, gagnez en"
    #define TEXT_NPC6 "puissance et en competences. (ps use /quests)"

typedef struct chat_stack {
    char *str;
    struct chat_stack *previous;
} chat_stack_t;

typedef struct chat_input {
    char c;
    struct chat_input *previous;
} chat_input_t;

typedef struct chat {
    sfRectangleShape *backgound;
    sfText *history_display;
    chat_stack_t *history;
    sfText *input_display;
    chat_input_t *input;
    sfBool to_display;
    sfClock *clock;
} chat_t;

void chat_input_add_letter(chat_input_t **chat, char to_add);
char *get_chat_input_content(chat_input_t *chat);
chat_input_t *chat_input_delete_char(chat_input_t *chat);
void chat_history_add(chat_stack_t **chat, char *to_add);
char *get_chat_history(chat_stack_t *stack);
void destroy_input(chat_input_t *chat);
int get_input_chat_size(chat_input_t *chat);
void add_to_chat(chat_t *chat, char *str);
