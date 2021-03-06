#pragma once

//=========================================================================──
//      DirectSound를사용하기위한헤더파일
//=========================================================================──
#include <d3dx9.h>
#include <mmsystem.h>
#include <DSound.h>

//=========================================================================──
//      DirectSound를사용하기위한라이브러리
//=========================================================================──
#pragma comment (lib , "dxerr.lib")
#pragma comment (lib , "winmm.lib")
#pragma comment (lib , "dsound.lib")
#pragma comment (lib , "dxguid.lib")

//=========================================================================──
//      전처리부분
//=========================================================================──
#define SOUNDBUFFER_SIZE        50


//=========================================================================
//      CDirectSound 
//=========================================================================
class CGSoundManager
{
private:
	//=========================================================================
	//      - 사운드재생에필요한변수
	//=========================================================================
	HWND                    m_hWnd; // 핸들
	LPDIRECTSOUND           m_lpDS; // 사운드버퍼
	LPDIRECTSOUNDBUFFER     m_ArrlpDSBuf[SOUNDBUFFER_SIZE];         // 사운드버퍼배열
	int m_SoundBufferIndex;                    // 사운드버퍼의위치

public:
	//=========================================================================
	//      + 생성자& 소멸자
	//=========================================================================
	CGSoundManager(HWND hWnd = NULL);
	virtual ~CGSoundManager(void);

	//=========================================================================
	//      + 프로퍼티
	//=========================================================================
	void                SetHwnd(HWND hWnd)      { this->m_hWnd = hWnd; }       // 핸들Set
	HWND                GetHwnd()               { return m_hWnd; }       // 핸들Get
	int                 GetBufferSize()         { return m_SoundBufferIndex; }

	//=========================================================================
	//      + DirectSound 초기화
	//=========================================================================
	void                DirectSoundInit(HWND hWnd = NULL);

	//=========================================================================
	//      + Wav파일을불러와서저장함
	//=========================================================================
	LPDIRECTSOUNDBUFFER LoadWav(TCHAR* wav);

	//=========================================================================
	//      + 재생( TRUE이면반복재생)
	//=========================================================================
	void                Play(int index, BOOL Loop = FALSE);

	//=========================================================================
	//      + 스톱
	//=========================================================================
	void                Stop(int index);
	void                AllStop();

	//=========================================================================
	//      + 좌우밸런스조절( 사운드)
	//=========================================================================
	void                SetPan(int index, long pan);

	//=========================================================================
	//      + 볼륨조절
	//=========================================================================
	void                SetVol(int index, long vol);

	//=========================================================================
	//      + 현재재생중인가..
	//=========================================================================
	BOOL                IsPlaying(int index);

	//=========================================================================
	//      + 사운드버퍼의Empty상태확인
	//=========================================================================
	BOOL                IsBufIndex(int index);

	//=========================================================================
	//      + 사운드버퍼배열에추가
	//=========================================================================
	int                 AddSoundBuffer(LPDIRECTSOUNDBUFFER buffer);

	//=========================================================================
	//      + 사운드버퍼배열에서삭제
	//=========================================================================
	void                DeleteSoundBuffer(int iDel_index);

	//=========================================================================
	//      + 에러메세지처리
	//=========================================================================
	void                DirectSoundError(TCHAR *errorString);

};