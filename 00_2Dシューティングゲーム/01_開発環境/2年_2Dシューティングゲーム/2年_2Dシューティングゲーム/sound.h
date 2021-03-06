//=============================================================================
//
// サウンド処理 [sound.h]
// Author : Konishi Yuuto
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

//=============================================================================
// インクルード
//=============================================================================
#include "main.h"
#include "xaudio2.h"		// サウンド処理で必要

//=============================================================================
// サウンドクラス
//=============================================================================
class CSound
{
public:
	//=============================================================================
	// サウンドファイル
	//=============================================================================
	typedef enum
	{
		SOUND_LABEL_TITLE = 0,			// タイトル
		SOUND_LABEL_GAME,				// ゲーム
		SOUND_LABEL_RESULT,				// リザルト
		SOUND_LABEL_BUTTON,				// ボタン
		SOUND_LABEL_SHOT,				// ボタン
		SOUND_LABEL_EXPLOSION,			// 爆発
		SOUND_LABEL_BOSS_EXPLOSION,		// ボスの爆発
		SOUND_LABEL_LASER,				// レーザー
		SOUND_LABEL_BOMB,				// ボム
		SOUND_LABEL_ICON,				// アイコン
		SOUND_LABEL_MESSAGE,			// メッセージ
		SOUND_LABEL_ARERT,				// アラート
		SOUND_LABEL_WARNING,			// WARNING
		SOUND_LABEL_BOSS,				// ボス
		SOUND_LABEL_HIT,				// ボス
		SOUND_LABEL_CHANGE,				// ボスの火花の音
		SOUND_LABEL_MAX,
	} SOUND_LABEL;

	//=============================================================================
	// パラメータ構造体定義
	//=============================================================================
	typedef struct
	{
		char *pFilename;	// ファイル名
		int nCntLoop;		// ループカウント
	} SOUNDPARAM;

	CSound();		// コンストラクタ
	~CSound();		// デストラクタ

	HRESULT Init(HWND hWnd);			// 初期化処理
	void Uninit(void);					// 終了処理
	HRESULT Play(SOUND_LABEL label);	// サウンド再生
	void Stop(SOUND_LABEL label);		// サウンド終了
	void Stop(void);
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

private:
	IXAudio2 *m_pXAudio2 = NULL;								// XAudio2オブジェクトへのインターフェイス
	IXAudio2MasteringVoice *m_pMasteringVoice = NULL;			// マスターボイス
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX] = {};	// ソースボイス
	BYTE *m_apDataAudio[SOUND_LABEL_MAX] = {};					// オーディオデータ
	DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};					// オーディオデータサイズ

	// 各音素材のパラメータ
	SOUNDPARAM m_aParam[SOUND_LABEL_MAX] =
	{
		{ "data/SOUND/title.wav", -1 },				// タイトル
		{ "data/SOUND/game.wav", -1 },				// ゲーム
		{ "data/SOUND/result.wav", -1 },			// リザルト
		{ "data/SOUND/button000.wav", 0 },			// ボタン
		{ "data/SOUND/shot.wav", 0 },				// ショット
		{ "data/SOUND/explosion000.wav", 0 },		// 爆発
		{ "data/SOUND/BossExplosion.wav", 0 },		// ボスの爆発
		{ "data/SOUND/laser000.wav", -1 },			// レーザー
		{ "data/SOUND/bomb.wav", 0 },				// ボム
		{ "data/SOUND/icon.wav", 0 },				// アイコン
		{ "data/SOUND/message.wav", 0 },			// メッセージ
		{ "data/SOUND/alert.wav", -1 },				// アラート
		{ "data/SOUND/warning.wav", 0 },			// WARNING
		{ "data/SOUND/boss.wav", 0 },				// ボス
		{ "data/SOUND/Hit.wav", 0 },				// ボスのヒット
		{ "data/SOUND/change.wav", -1 },			// ボスのヒット
	};
};

#endif
