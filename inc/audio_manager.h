/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** audio_manager
*/

#pragma once

    #include <SFML/Audio.h>
    #include "wcsv.h"

    #define AUDIO_C_F "config/audio.csv"
    #define AUDIO_LF "name, path"
    #define MAX_SOUNDS 10
    /* STOP MUSCI */
    #define MUSIC_STOP(manager) sfMusic_stop(manager->m_current)
    /* RESUME MUSCI */
    #define MUSIC_RESUME(manager) sfMusic_play(manager->m_current)
    /* PAUSE MUSCI */
    #define MUSIC_PAUSE(manager) sfMusic_pause(manager->m_current)

typedef struct audio {
    sfMusic *m_current;
    sfSound **s_current;
    wcsv_t *csv;
} audio_t;

audio_t *create_audio_manager(void);
void play_music(audio_t *manager, char *name);
sfMusic *load_audio(audio_t *audio, char *name);
void play_sound(audio_t *manager, char *name);
sfSoundBuffer *load_sound_buffer(audio_t *audio, char *name);
sfMusic *load_music(audio_t *audio, char *name);
void destroy_audio_manager(audio_t *manager);
