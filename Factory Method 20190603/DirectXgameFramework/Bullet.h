#ifndef BULLET_DEFINED
#define BULLET_DEFINED
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <WICTextureLoader.h>
#include "DirectX11.h"
#include "StepTimer.h"
#include "BulletFactory.h"
class BulletFactory;
// 弾クラス
class Bullet
{
public:
	// 弾のサイズ
	static const int SIZE = 16;
	// 使用中かどうかを取得する
	bool IsUsed()
	{
		return m_used;
	}
	// 使用中かどうかを設定する
	void IsUsed(bool used)
	{
		m_used = used;
	}
	// 位置を取得する
	DirectX::SimpleMath::Vector2 GetPosition() const
	{
		return m_position;
	}
	// 位置を設定する
	void SetPosition(const DirectX::SimpleMath::Vector2& position)
	{
		m_position = position;
	}
	// 弾回転角を取得する
	float GetAngle() const
	{
		return m_angle;
	}
	// 弾回転角を設定する
	void SetAngle(const float& angle)
	{
		m_angle = angle;
	}
	// 色を取得する
	DirectX::SimpleMath::Vector4 GetColor() const
	{
		return m_color;
	}
	// 色を設定する
	void SetColor(const DirectX::SimpleMath::Vector4& color)
	{
		m_color = color;
	}
	// コンストラクタ
	Bullet();
	// 初期化する
	void Initialize(BulletFactory* bulletFactory);
	// Bulletオブジェクトを更新する
	void Update(const DX::StepTimer& timer);
	// Bulletオブジェクトを描画する
	void Render(DirectX::SpriteBatch& spriteBatch);
	// Bulletオブジェクトの後処理をおこなう
	void Finalize();
private:
	// 弾スピードを定義する
	static const DirectX::SimpleMath::Vector2 SPEED;
	// 弾を使用しているかどうかを示す
	bool m_used;
	// 角度
	float m_angle;
	// 位置
	DirectX::SimpleMath::Vector2 m_position;
	// 色
	DirectX::SimpleMath::Vector4 m_color;
	// テクスチャ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_bulletTexture;
};
#endif // BULLET_DEFINED