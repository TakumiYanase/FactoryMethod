#include "BulletFactory.h"
// コンストラクタ
BulletFactory::BulletFactory()
{
}
// 初期化する
void BulletFactory::Initialize()
{
	// 配列のサイズを設定する
	m_bulletArray.resize(BULLET_NUM);
	// Bulletテクスチャをロードする
	DirectX::CreateWICTextureFromFile(DirectX11::Get().GetDevice().Get(),
		L"bullet.png", nullptr, m_bulletTexture.ReleaseAndGetAddressOf());
	// Bulletオブジェクトを生成し配列に格納する
	for (int i = 0; i < BULLET_NUM; i++)
	{
		// Bulletオブジェクトを生成する
		m_bulletArray[i] = std::make_unique<Bullet>();
		// 弾を使用可能にする
		m_bulletArray[i]->IsUsed(false);
		// 初期化する
		m_bulletArray[i]->Initialize(this);
	}
}
// 弾を生成する
Bullet* BulletFactory::Create(const DirectX::SimpleMath::Vector2& position, const
	float& angle)
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		// 弾を使用していないければ
		if (m_bulletArray[i]->IsUsed() == false)
		{
			// 弾は「飛行中」を設定する
			m_bulletArray[i]->IsUsed(true);
			// 弾に飛行角度を設定する
			m_bulletArray[i]->SetAngle(angle);
			// 飛行開始位置を設定する
			m_bulletArray[i]->SetPosition(position);
			// Bulletオブジェクトを返す
			return m_bulletArray[i].get();
		}
	}
	return nullptr;
}
// 後始末をする
void BulletFactory::Finalize()
{
	// Bulletオブジェクトを破棄する
	for (int i = 0; i < BULLET_NUM; i++)
	{
		// Bulletオブジェクトを破棄する
		if (m_bulletArray[i] != nullptr)
			m_bulletArray[i].reset();
	}
	// Bullet配列を破棄する
	m_bulletArray.clear();
}