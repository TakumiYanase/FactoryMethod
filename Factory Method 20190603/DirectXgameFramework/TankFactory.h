#ifndef TANK_FACTORY
#define TANK_FACTORY
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <SimpleMath.h>
#include "Tank.h"
#include "Turret.h"
#include "Body.h"
#include "Cannon.h"
// Tankファクトリクラス
class TankFactory
{
public:
	// コンストラクタ
	TankFactory(DirectX::SimpleMath::Vector2& position, float angle,
		DirectX::SimpleMath::Vector4& color);
	// タンクのパーツを生成する
	Tank* Create(Tank::PARTS_ID id);
private:
	// 位置
	DirectX::SimpleMath::Vector2 m_position;
	// 速度
	DirectX::SimpleMath::Vector2 m_velocity;
	// 車体角
	float m_angle;
	// 砲塔角
	float m_turretAngle;
	// 色 Color
	DirectX::SimpleMath::Vector4 m_color;
};
#endif // TANK_FACTORY