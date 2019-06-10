#include "Cannon.h"
// コンストラクタ
Cannon::Cannon()
{
}
// パーツを追加する
void Cannon::AddParts(Tank* tank)
{
}
// パーツを取得する
Tank* Cannon::GetParts()
{
	return nullptr;
}
// 初期化する
void Cannon::Initialize()
{
	// 主砲テクスチャをロードする
	DirectX::CreateWICTextureFromFile(DirectX11::Get().GetDevice().Get(),
		L"tank4.png", nullptr, m_texture.ReleaseAndGetAddressOf());
}
// 更新する
void Cannon::Update(const DX::StepTimer& timer)
{
}
// 描画する
void Cannon::Render(DirectX::SpriteBatch& spriteBatch, DirectX::SimpleMath::Vector2&
	position, float angle, DirectX::SimpleMath::Vector4& color)
{
	// スプライトを描画する
	spriteBatch.Draw(m_texture.Get(), position, nullptr, color, -angle +
		DirectX::XMConvertToRadians(90.0f), DirectX::SimpleMath::Vector2(64.0f, 64.0f));
}
// 後処理をおこなう
void Cannon::Finalize()
{
	// テクスチャをリセットする
	m_texture.Reset();
}