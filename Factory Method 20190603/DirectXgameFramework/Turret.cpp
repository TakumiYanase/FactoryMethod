#include "Turret.h"
// コンストラクタ
Turret::Turret()
{
}
// パーツを追加する
void Turret::AddParts(Tank* tank)
{
	// パーツを設定する
	m_tank = tank;
}
// パーツを取得する
Tank* Turret::GetParts()
{
	return m_tank;
}
// 初期化する
void Turret::Initialize()
{
	// Turretテクスチャをロードする
	DirectX::CreateWICTextureFromFile(DirectX11::Get().GetDevice().Get(),
		L"tank3.png", nullptr, m_texture.ReleaseAndGetAddressOf());
}
// 更新する
void Turret::Update(const DX::StepTimer& timer)
{
}
// 描画する
void Turret::Render(DirectX::SpriteBatch& spriteBatch, DirectX::SimpleMath::Vector2&
	position, float angle, DirectX::SimpleMath::Vector4& color)
{
	// スプライトを描画する
	spriteBatch.Draw(m_texture.Get(), position, nullptr, color, -angle +
		DirectX::XMConvertToRadians(90.0f), DirectX::SimpleMath::Vector2(64.0f, 64.0f));
	if (m_tank != nullptr)
		// Render関数を呼び出す
		m_tank->Render(spriteBatch, position, angle + GetTurretAngle(), color);
}
// 後処理をおこなう
void Turret::Finalize()
{
	// テクスチャをリセットする
	m_texture.Reset();

	if (m_tank!=nullptr)
	{

	}
}