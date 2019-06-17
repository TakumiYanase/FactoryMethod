#ifndef BULLET_FACTORY_DEFINED
#define BULLET_FACTORY_DEFINED
#include <vector>
#include "Bullet.h"
class Bullet;
class BulletFactory
{
public:
	// �e��
	static const int BULLET_NUM = 30;
	// �e�N�X�`�����擾����
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> GetBulletTexture()
	{
		return m_bulletTexture;
	}
	// �R���X�g���N�^
	BulletFactory();
	// ����������
	void Initialize();
	// �e�𔭎˂���
	Bullet* Create(const DirectX::SimpleMath::Vector2& position, const float& angle);
	// ��n��������
	void Finalize();
private:
	// �e�e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_bulletTexture;
	// �e�z��
	std::vector<std::unique_ptr<Bullet>> m_bulletArray;
};
#endif // BULLET_FACTORY_DEFINED