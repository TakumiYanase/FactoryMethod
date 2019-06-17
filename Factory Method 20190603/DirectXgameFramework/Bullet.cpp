#include "Bullet.h"
// �e�X�s�[�h���`����
const DirectX::SimpleMath::Vector2 Bullet::SPEED(4.0f, 0.0f);
// �R���X�g���N�^
Bullet::Bullet() : m_used(false), m_angle(0.0f), m_position(0.0f, 0.0f)
{
}
// ����������
void Bullet::Initialize(BulletFactory* bulletFactory)
{
	// �e�N�X�`�����擾����
	m_bulletTexture = bulletFactory->GetBulletTexture();
}
// Bullet�I�u�W�F�N�g���X�V����
void Bullet::Update(const DX::StepTimer& timer)
{
	// �o�ߎ��Ԃ��擾����
	float elapsedTime = float(timer.GetElapsedSeconds());
	// �e����]����
	DirectX::SimpleMath::Matrix rotation =
		DirectX::SimpleMath::Matrix::CreateRotationZ(m_angle);
	// ���x���v�Z����
	DirectX::SimpleMath::Vector2 velocity =
		DirectX::SimpleMath::Vector2::TransformNormal(SPEED, rotation);
	// �ړ�����
	m_position += velocity;
}
// Bullet�I�u�W�F�N�g��`�悷��
void Bullet::Render(DirectX::SpriteBatch& spriteBatch)
{
	// �X�v���C�g��`�悷��
	spriteBatch.Draw(m_bulletTexture.Get(), m_position, nullptr,
		DirectX::Colors::White, m_angle + DirectX::XMConvertToRadians(90.0f),
		DirectX::SimpleMath::Vector2(8.0f, 8.0f));
}
// Bullet�I�u�W�F�N�g�̌㏈���������Ȃ�
void Bullet::Finalize()
{
}