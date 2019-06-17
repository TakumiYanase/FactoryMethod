#include "BulletFactory.h"
// �R���X�g���N�^
BulletFactory::BulletFactory()
{
}
// ����������
void BulletFactory::Initialize()
{
	// �z��̃T�C�Y��ݒ肷��
	m_bulletArray.resize(BULLET_NUM);
	// Bullet�e�N�X�`�������[�h����
	DirectX::CreateWICTextureFromFile(DirectX11::Get().GetDevice().Get(),
		L"bullet.png", nullptr, m_bulletTexture.ReleaseAndGetAddressOf());
	// Bullet�I�u�W�F�N�g�𐶐����z��Ɋi�[����
	for (int i = 0; i < BULLET_NUM; i++)
	{
		// Bullet�I�u�W�F�N�g�𐶐�����
		m_bulletArray[i] = std::make_unique<Bullet>();
		// �e���g�p�\�ɂ���
		m_bulletArray[i]->IsUsed(false);
		// ����������
		m_bulletArray[i]->Initialize(this);
	}
}
// �e�𐶐�����
Bullet* BulletFactory::Create(const DirectX::SimpleMath::Vector2& position, const
	float& angle)
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		// �e���g�p���Ă��Ȃ������
		if (m_bulletArray[i]->IsUsed() == false)
		{
			// �e�́u��s���v��ݒ肷��
			m_bulletArray[i]->IsUsed(true);
			// �e�ɔ�s�p�x��ݒ肷��
			m_bulletArray[i]->SetAngle(angle);
			// ��s�J�n�ʒu��ݒ肷��
			m_bulletArray[i]->SetPosition(position);
			// Bullet�I�u�W�F�N�g��Ԃ�
			return m_bulletArray[i].get();
		}
	}
	return nullptr;
}
// ��n��������
void BulletFactory::Finalize()
{
	// Bullet�I�u�W�F�N�g��j������
	for (int i = 0; i < BULLET_NUM; i++)
	{
		// Bullet�I�u�W�F�N�g��j������
		if (m_bulletArray[i] != nullptr)
			m_bulletArray[i].reset();
	}
	// Bullet�z���j������
	m_bulletArray.clear();
}