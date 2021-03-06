#ifndef _TIME_H_
#define _TIME_H_
//=============================================================================
//
// タイムクラスヘッダー [time.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "scene.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define MAX_TIME		(4)		// 桁数
#define TIME_SIZE_X	(15.0f)		// スコアの縦のサイズ
#define TIME_SIZE_Y	(30.0f)		// スコアの横のサイズ

//=============================================================================
// 前置宣言
//=============================================================================
class CNumber;

//=============================================================================
// レンダラークラス
//=============================================================================
class CTime : public CScene
{
public:
	CTime(TYPE Priority = TYPE_SCORE);	// コンストラクタ
	~CTime();							// デストラクタ

	// メンバ関数
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, TYPE type);	// 初期化処理
	void Uninit(void);											// 終了処理
	void Update(void);											// 更新処理
	void Draw(void);											// 描画処理

	int GetTime(void);
	static bool GetRetire(void);								// ボスの撤退情報

private:
	CNumber *m_apNumber[MAX_TIME];		// 桁数分
	int m_nTime;						// タイム
	DWORD m_dwBossStartTime;			// ボスのスタート
	static bool m_bRetire;				// ボスの撤退フラグ
};

#endif