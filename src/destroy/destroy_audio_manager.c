/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** destroy_audio_manager
*/

#include "audio_manager.h"
#include "destroy.h"

void destroy_audio_manager(audio_t *manager)
{
    wcsv_destroy(manager->csv);
    free(manager->s_current);
    free(manager);
}
