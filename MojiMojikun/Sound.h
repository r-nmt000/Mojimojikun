#pragma once
#include "Common.h"
#include <Mmsystem.h>
#include <Windows.h>
#include <SDL.h>
#include <SDL_mixer.h>

void SoundInit();

DWORD WINAPI ControlSoundProc( LPVOID String );
void ControlSound(LPCWSTR String);

DWORD WINAPI PlayBGMProc( LPVOID String );
void PlayBGM(LPCWSTR String);

