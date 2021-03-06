//=============================================================================
//
// タイムクラス [time.cpp]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "time.h"
#include "manager.h"
#include "renderer.h"
#include "number.h"
#include "boss.h"
#include "game.h"
#include "texture.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define TIME_INTERVAL	(25.0f)			// 数字の間隔
#define BOSS_TIME		(1200)			// 数字の間隔

//=============================================================================
// static初期化
//=============================================================================
bool CTime::m_bRetire = false;

//=============================================================================
// コンストラクタ
//=============================================================================
CTime::CTime(TYPE Priority): CScene(Priority)
{
	m_nTime = BOSS_TIME;
	m_dwBossStartTime = GetBossCurrentTime();
	m_bRetire = false;
}

//=============================================================================
// デストラクタ
//=============================================================================
CTime::~CTime()
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CTime::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, TYPE type)
{
	for (int nCount = 0; nCount < MAX_TIME; nCount++)
	{
		// 数字のメモリ確保
		m_apNumber[nCount] = CNumber::Create(pos, size, type, CNumber::NUMBER_TYPE_RANKING);
		m_apNumber[nCount]->BindTexture(CTexture::GetTexture(CTexture::TEXTURE_NUM_NUMBER_001));

		if (m_apNumber[nCount] != NULL)
		{
			// 数字の間隔をあける
			pos.x -= TIME_INTERVAL;

			// 数字の設定
			m_apNumber[nCount]->SetNumber(0);
		}
	}
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CTime::Uninit(void)
{
	for (int nCount = 0; nCount < MAX_TIME; nCount++)
	{
		// ナンバー終了処理
		if (m_apNumber[nCount] != NULL)
		{
			m_apNumber[nCount]->Uninit();
		}
	}

	// メモリの開放処理
	Release();
}

//=============================================================================
// 更新処理
//=============================================================================
void CTime::Update(void)
{
	// ボスの情報取得
	CBoss *pBoss = CGame::GetBoss();

	// ボスが死んでいなければ
	if (pBoss->GetExplosion() == false)
	{
		// 残り時間を求める
		DWORD dwGameTime = GetBossCurrentTime() - m_dwBossStartTime;
		int nTime = m_nTime - dwGameTime / 100;

		// 0じゃなかったら
		if (nTime > 0)
		{
			for (int nCount = 0; nCount < MAX_TIME; nCount++)
			{
				int nNum = (nTime / (int)(pow(10, nCount))) % 10;

				// 数字の設定
				m_apNumber[nCount]->SetNumber(nNum);
			}
		}
		else
		{
			for (int nCount = 0; nCount < MAX_TIME; nCount++)
			{
				// 数字の設定
				m_apNumber[nCount]->SetNumber(0);
			}
			m_bRetire = true;
		}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void CTime::Draw(void)
{
	for (int nCount = 0; nCount < MAX_TIME; nCount++)
	{
		if (m_apNumber[nCount] != NULL)
		{
			m_apNumber[nCount]->Draw();
		}
	}
}

//=============================================================================
// タイムの情報
//=============================================================================
int CTime::GetTime(void)
{
	return m_nTime;
}

//=============================================================================
// タイムのフラグ
//=============================================================================
bool CTime::GetRetire(void)
{
	return m_bRetire;
}