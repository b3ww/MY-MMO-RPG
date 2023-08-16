/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** create_audio_manager
*/

#include "wcsv.h"
#include "audio_manager.h"

void play_music(audio_t *manager, char *name)
{
    sfMusic *to_play = load_music(manager, name);

    if (!to_play)
        return;
    if (manager->m_current) {
        if (sfMusic_getStatus(manager->m_current) == sfPlaying) {
            sfMusic_stop(manager->m_current);
        }
    }
    manager->m_current = to_play;
    sfMusic_play(manager->m_current);
    sfMusic_setLoop(manager->m_current, sfTrue);
}

static bool update_sound(sfSound *sound)
{
    if (sfSound_getStatus(sound) == sfStopped) {
        return false;
    }
    return true;
}

void play_sound(audio_t *manager, char *name)
{
    sfSoundBuffer *to_play = load_sound_buffer(manager, name);
    sfSound *sound = sfSound_create();

    if (!to_play)
        return;
    sfSound_setBuffer(sound, to_play);
    for (int i = 0; i < MAX_SOUNDS; i++) {
        if (manager->s_current[i]) {
            manager->s_current[i] = update_sound(manager->s_current[i]) ?
            manager->s_current[i] : NULL;
            continue;
        }
        manager->s_current[i] = sound;
        sfSound_play(manager->s_current[i]);
        sfSoundBuffer_destroy(to_play);
        return;
    }
}

audio_t *create_audio_manager(void)
{
    audio_t *ret = malloc(sizeof(audio_t));

    ret->csv = wcsv_parse(AUDIO_C_F, AUDIO_LF, NULL);
    ret->m_current = NULL;
    ret->s_current = malloc(sizeof(sfSound *) * MAX_SOUNDS);
    for (int i = 0; i < MAX_SOUNDS; i++)
        ret->s_current[i] = NULL;
    return ret;
}
