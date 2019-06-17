#include "Bullet.h"
// 弾スピードを定義する
const DirectX::SimpleMath::Vector2 Bullet::SPEED(4.0f, 0.0f);
// コンストラクタ
Bullet::Bullet() : m_used(false), m_angle(0.0f), m_position(0.0f, 0.0f)
{
}
// 初期化する
void Bullet::Initialize(BulletFactory* bulletFactory)
{
	// テクスチャを取得する
	m_bulletTexture = bulletFactory->GetBulletTexture();
}
// Bulletオブジェクトを更新する
void Bullet::Update(const DX::StepTimer& timer)
{
	// 経過時間を取得する
	float elapsedTime = float(timer.GetElapsedSeconds());
	// 弾を回転する
	DirectX::SimpleMath::Matrix rotation =
		DirectX::SimpleMath::Matrix::CreateRotationZ(m_angle);
	// 速度を計算する
	DirectX::SimpleMath::Vector2 velocity =
		DirectX::SimpleMath::Vector2::TransformNormal(SPEED, rotation);
	// 移動する
	m_position += velocity;
}
// Bulletオブジェクトを描画する
void Bullet::Render(DirectX::SpriteBatch& spriteBatch)
{
	// スプライトを描画する
	spriteBatch.Draw(m_bulletTexture.Get(), m_position, nullptr,
		DirectX::Colors::White, m_angle + DirectX::XMConvertToRadians(90.0f),
		DirectX::SimpleMath::Vector2(8.0f, 8.0f));
}
// Bulletオブジェクトの後処理をおこなう
void Bullet::Finalize()
{
}