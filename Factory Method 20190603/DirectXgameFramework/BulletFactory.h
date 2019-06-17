#ifndef BULLET_FACTORY_DEFINED
#define BULLET_FACTORY_DEFINED
#include <vector>
#include "Bullet.h"
class Bullet;
class BulletFactory
{
public:
	// 弾数
	static const int BULLET_NUM = 30;
	// テクスチャを取得する
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> GetBulletTexture()
	{
		return m_bulletTexture;
	}
	// コンストラクタ
	BulletFactory();
	// 初期化する
	void Initialize();
	// 弾を発射する
	Bullet* Create(const DirectX::SimpleMath::Vector2& position, const float& angle);
	// 後始末をする
	void Finalize();
private:
	// 弾テクスチャ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_bulletTexture;
	// 弾配列
	std::vector<std::unique_ptr<Bullet>> m_bulletArray;
};
#endif // BULLET_FACTORY_DEFINED