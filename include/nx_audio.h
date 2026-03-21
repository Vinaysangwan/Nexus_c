#pragma once

#include "nx_utils.h"

// #############################################################################
//                           Audio Functions
// #############################################################################
bool audio_init(void);
void audio_close(void);

// #############################################################################
//                           Sound Functions
// #############################################################################
typedef struct NxSound NxSound;

NxSound* sound_load(const char* path);
void sound_free(NxSound* sound);

void sound_play(NxSound* sound);

void sound_set_volume(NxSound* sound, float volume);
float sound_get_volume(NxSound* sound);

// #############################################################################
//                           music Functions
// #############################################################################
typedef struct NxMusic NxMusic;

NxMusic* music_load(const char* path);
void music_free(NxMusic* music);

void music_play(NxMusic* music);
void music_stop(NxMusic* music);
void music_pause(NxMusic* music);
void music_resume(NxMusic* music);
bool music_is_playing(NxMusic* music);

void music_set_volume(NxMusic* music, float volume);
float music_get_volume(NxMusic* music);
