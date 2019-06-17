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
// �e�N���X
class Bullet
{
public:
	// �e�̃T�C�Y
	static const int SIZE = 16;
	// �g�p�����ǂ������擾����
	bool IsUsed()
	{
		return m_used;
	}
	// �g�p�����ǂ�����ݒ肷��
	void IsUsed(bool used)
	{
		m_used = used;
	}
	// �ʒu���擾����
	DirectX::SimpleMath::Vector2 GetPosition() const
	{
		return m_position;
	}
	// �ʒu��ݒ肷��
	void SetPosition(const DirectX::SimpleMath::Vector2& position)
	{
		m_position = position;
	}
	// �e��]�p���擾����
	float GetAngle() const
	{
		return m_angle;
	}
	// �e��]�p��ݒ肷��
	void SetAngle(const float& angle)
	{
		m_angle = angle;
	}
	// �F���擾����
	DirectX::SimpleMath::Vector4 GetColor() const
	{
		return m_color;
	}
	// �F��ݒ肷��
	void SetColor(const DirectX::SimpleMath::Vector4& color)
	{
		m_color = color;
	}
	// �R���X�g���N�^
	Bullet();
	// ����������
	void Initialize(BulletFactory* bulletFactory);
	// Bullet�I�u�W�F�N�g���X�V����
	void Update(const DX::StepTimer& timer);
	// Bullet�I�u�W�F�N�g��`�悷��
	void Render(DirectX::SpriteBatch& spriteBatch);
	// Bullet�I�u�W�F�N�g�̌㏈���������Ȃ�
	void Finalize();
private:
	// �e�X�s�[�h���`����
	static const DirectX::SimpleMath::Vector2 SPEED;
	// �e���g�p���Ă��邩�ǂ���������
	bool m_used;
	// �p�x
	float m_angle;
	// �ʒu
	DirectX::SimpleMath::Vector2 m_position;
	// �F
	DirectX::SimpleMath::Vector4 m_color;
	// �e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_bulletTexture;
};
#endif // BULLET_DEFINED