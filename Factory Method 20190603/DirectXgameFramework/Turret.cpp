#include "Turret.h"
// �R���X�g���N�^
Turret::Turret()
{
}
// �p�[�c��ǉ�����
void Turret::AddParts(Tank* tank)
{
	// �p�[�c��ݒ肷��
	m_tank = tank;
}
// �p�[�c���擾����
Tank* Turret::GetParts()
{
	return m_tank;
}
// ����������
void Turret::Initialize()
{
	// Turret�e�N�X�`�������[�h����
	DirectX::CreateWICTextureFromFile(DirectX11::Get().GetDevice().Get(),
		L"tank3.png", nullptr, m_texture.ReleaseAndGetAddressOf());
}
// �X�V����
void Turret::Update(const DX::StepTimer& timer)
{
}
// �`�悷��
void Turret::Render(DirectX::SpriteBatch& spriteBatch, DirectX::SimpleMath::Vector2&
	position, float angle, DirectX::SimpleMath::Vector4& color)
{
	// �X�v���C�g��`�悷��
	spriteBatch.Draw(m_texture.Get(), position, nullptr, color, -angle +
		DirectX::XMConvertToRadians(90.0f), DirectX::SimpleMath::Vector2(64.0f, 64.0f));
	if (m_tank != nullptr)
		// Render�֐����Ăяo��
		m_tank->Render(spriteBatch, position, angle + GetTurretAngle(), color);
}
// �㏈���������Ȃ�
void Turret::Finalize()
{
	// �e�N�X�`�������Z�b�g����
	m_texture.Reset();

	if (m_tank!=nullptr)
	{

	}
}