/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** create_audio
*/

#include "audio_manager.h"

sfMusic *load_music(audio_t *audio, char *name)
{
    char *path = wcsv_get(audio->csv, (wcsv_req_t){name, VALUE, "path",
    LFORMAT});

    if (!path)
        return NULL;
    return sfMusic_createFromFile(path);
}

sfSoundBuffer *load_sound_buffer(audio_t *audio, char *name)
{
    char *path = wcsv_get(audio->csv, (wcsv_req_t){name, VALUE, "path",
    LFORMAT});

    if (!path)
        return NULL;
    return sfSoundBuffer_createFromFile(path);
}
