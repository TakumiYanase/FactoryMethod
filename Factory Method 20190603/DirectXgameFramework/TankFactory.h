#ifndef TANK_FACTORY
#define TANK_FACTORY
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <SimpleMath.h>
#include "Tank.h"
#include "Turret.h"
#include "Body.h"
#include "Cannon.h"
// Tank�t�@�N�g���N���X
class TankFactory
{
public:
	// �R���X�g���N�^
	TankFactory(DirectX::SimpleMath::Vector2& position, float angle,
		DirectX::SimpleMath::Vector4& color);
	// �^���N�̃p�[�c�𐶐�����
	Tank* Create(Tank::PARTS_ID id);
private:
	// �ʒu
	DirectX::SimpleMath::Vector2 m_position;
	// ���x
	DirectX::SimpleMath::Vector2 m_velocity;
	// �ԑ̊p
	float m_angle;
	// �C���p
	float m_turretAngle;
	// �F Color
	DirectX::SimpleMath::Vector4 m_color;
};
#endif // TANK_FACTORY