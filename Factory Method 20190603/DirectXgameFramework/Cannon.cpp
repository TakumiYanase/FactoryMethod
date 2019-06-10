#include "Cannon.h"
// �R���X�g���N�^
Cannon::Cannon()
{
}
// �p�[�c��ǉ�����
void Cannon::AddParts(Tank* tank)
{
}
// �p�[�c���擾����
Tank* Cannon::GetParts()
{
	return nullptr;
}
// ����������
void Cannon::Initialize()
{
	// ��C�e�N�X�`�������[�h����
	DirectX::CreateWICTextureFromFile(DirectX11::Get().GetDevice().Get(),
		L"tank4.png", nullptr, m_texture.ReleaseAndGetAddressOf());
}
// �X�V����
void Cannon::Update(const DX::StepTimer& timer)
{
}
// �`�悷��
void Cannon::Render(DirectX::SpriteBatch& spriteBatch, DirectX::SimpleMath::Vector2&
	position, float angle, DirectX::SimpleMath::Vector4& color)
{
	// �X�v���C�g��`�悷��
	spriteBatch.Draw(m_texture.Get(), position, nullptr, color, -angle +
		DirectX::XMConvertToRadians(90.0f), DirectX::SimpleMath::Vector2(64.0f, 64.0f));
}
// �㏈���������Ȃ�
void Cannon::Finalize()
{
	// �e�N�X�`�������Z�b�g����
	m_texture.Reset();
}