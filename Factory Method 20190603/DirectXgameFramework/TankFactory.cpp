#include "TankFactory.h"
// コンストラクタ
TankFactory::TankFactory(DirectX::SimpleMath::Vector2& position, float angle,
	DirectX::SimpleMath::Vector4& color)
	:
	m_position(position), m_angle(angle), m_turretAngle(angle), m_color(color)
{
}
// タンクのパーツを生成する
Tank* TankFactory::Create(Tank::PARTS_ID id)
{
	Tank* tank;
	switch (id)
	{
	case Tank::PARTS_ID::BODY:
		// Bodyオブジェクトを生成する
		tank = new Body();
		// 車体の位置を設定する
		tank->SetPosition(m_position);
		// 車体の回転角を設定する
		tank->SetBodyAngle(m_angle);
		// 車体の色を設置する
		tank->SetColor(m_color);
		break;
	case Tank::PARTS_ID::TURRET:
		// 砲塔オブジェクトを生成する
		tank = new Turret();
		break;
	case Tank::PARTS_ID::CANNON:
		// 主砲オブジェクトを生成する
		tank = new Cannon();
		break;
	default:
		return nullptr;
	}
	// それぞれのタンクパーツを初期化する
	tank->Initialize();
	return tank;
}