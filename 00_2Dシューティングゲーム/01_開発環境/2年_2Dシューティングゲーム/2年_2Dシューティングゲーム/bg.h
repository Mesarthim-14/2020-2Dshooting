#ifndef _BG_H_
#define _BG_H_
//=============================================================================
//
// BGクラスヘッダー [bg.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "scene.h"
#include "scene2d.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define BG_SIZE_X (600)			// 背景の横幅
#define BG_SIZE_Y (400)			// 背景の縦幅

//=============================================================================
// 前方宣言
//=============================================================================
class CScene;
class CScene2D;

//=============================================================================
// BGクラス
//=============================================================================
class CBackground : public CScene
{
public:
	CBackground(TYPE Priority = TYPE_BG);	// コンストラクタ
	~CBackground();							// デストラクタ

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, TYPE type);	// 初期化処理
	void Uninit(void);											// 終了処理
	void Update(void);											// 更新処理
	void Draw(void);											// 描画処理

	static CBackground * Create(
		D3DXVECTOR3 pos, D3DXVECTOR3 size, TYPE type);			// インスタンス生成

private:
	CScene2D *m_apScene2D[MAX_POLYGON];							// scene2D情報のポインタ
};

#endif