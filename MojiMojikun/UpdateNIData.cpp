#include "Common.h"
#include "passage.h"
#include <Mmsystem.h>
#include <Windows.h>
#include "NomoTex.h"


//�L�l�N�g�̃f�[�^�̍X�V�͂�����̃X���b�h�ɔC����
DWORD WINAPI UpdateNIDataProc(LPVOID)
{
	while(1){
		g_Context.WaitOneUpdateAll(g_DepthGenerator);
		passage::passage_main ();
		if(ExitNIThreadFlg){
			DWORD dwExitCode = NULL;
			ExitThread(dwExitCode);
		}
	}
}
void UpdateNIData( )
{
	HANDLE hThread = NULL;
	if( (hThread = CreateThread(NULL, 0, UpdateNIDataProc, (LPVOID)NULL, 0, NULL) ) != NULL ){
		CloseHandle(hThread);
	}
}

