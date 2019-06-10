#include "TankFactory.h"
// �R���X�g���N�^
TankFactory::TankFactory(DirectX::SimpleMath::Vector2& position, float angle,
	DirectX::SimpleMath::Vector4& color)
	:
	m_position(position), m_angle(angle), m_turretAngle(angle), m_color(color)
{
}
// �^���N�̃p�[�c�𐶐�����
Tank* TankFactory::Create(Tank::PARTS_ID id)
{
	Tank* tank;
	switch (id)
	{
	case Tank::PARTS_ID::BODY:
		// Body�I�u�W�F�N�g�𐶐�����
		tank = new Body();
		// �ԑ̂̈ʒu��ݒ肷��
		tank->SetPosition(m_position);
		// �ԑ̂̉�]�p��ݒ肷��
		tank->SetBodyAngle(m_angle);
		// �ԑ̂̐F��ݒu����
		tank->SetColor(m_color);
		break;
	case Tank::PARTS_ID::TURRET:
		// �C���I�u�W�F�N�g�𐶐�����
		tank = new Turret();
		break;
	case Tank::PARTS_ID::CANNON:
		// ��C�I�u�W�F�N�g�𐶐�����
		tank = new Cannon();
		break;
	default:
		return nullptr;
	}
	// ���ꂼ��̃^���N�p�[�c������������
	tank->Initialize();
	return tank;
}