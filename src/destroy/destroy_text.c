/*
** EPITECH PROJECT, 2023
** src/destroy/destroy_text
** File description:
** destroy test
*/

#include "destroy.h"
#include "text.h"

void destroy_text(text_t *text)
{
    sfFont_destroy(text->font);
    sfText_destroy(text->text);
    free(text->str);
    free(text);
}
