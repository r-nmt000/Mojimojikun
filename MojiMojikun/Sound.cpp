#pragma once
#include "Sound.h"

//SDL_MixerÇÃèâä˙âª
void SoundInit(){
	SDL_Init(0x00000010);                     // SDLèâä˙âª
    Mix_OpenAudio(22050,AUDIO_S16,2,4096);    // SDL_MixerÉIÅ[ÉvÉì
	Mix_AllocateChannels(16);                // ìØéûî≠ê∫êî
}

//âπä÷åWÇÃêßå‰ä÷êî
DWORD WINAPI ControlSoundProc( LPVOID String ){
	g_SoundFlg = true;
	PlaySound( (LPCWSTR)String, NULL, SND_FILENAME|SND_SYNC );
	g_SoundFlg = false;
	return 1;
}

void ControlSound(LPCWSTR String){
	HANDLE hThread = NULL;
	if( (hThread = CreateThread(NULL, 0, ControlSoundProc, (LPVOID)String, 0, NULL) ) != NULL ){
		CloseHandle(hThread);
	}
}
/*
void ControlSound(LPCWSTR String){
	g_SoundFlg = true;
	Mix_Chunk *ch;
	ch = Mix_LoadWAV(String);
	Mix_PlayChannel( -1, ch, 0 );
	g_SoundFlg = false;
}*/

//BGMêßå‰
DWORD WINAPI PlayBGMProc( LPVOID String ){
	g_PlayBGMFlg = TRUE;
	PlaySound( (LPCWSTR)String, NULL, SND_FILENAME|SND_LOOP|SND_ASYNC );
	while(g_PlayBGMFlg){
		;
	}
	return 1;
}
void PlayBGM(LPCWSTR String){
	HANDLE hThread = NULL;
	if( (hThread = CreateThread(NULL, 0, PlayBGMProc, (LPVOID)String, 0, NULL) ) != NULL ){
		CloseHandle(hThread);
	}
}
