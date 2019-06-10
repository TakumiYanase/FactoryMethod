#include "Player.h"

// �R���X�g���N�^
Player::Player() 
{
}

// ����������
void Player::Initialize(DirectX::SimpleMath::Vector2 position, float angle, DirectX::SimpleMath::Vector4 color)
{
	// Keyboard�I�u�W�F�N�g�𐶐�����
	m_keyboard = std::make_unique<DirectX::Keyboard>();
	// KeyboardStateTracker�I�u�W�F�N�g�𐶐�����
	m_keyboardTracker = std::make_unique<DirectX::Keyboard::KeyboardStateTracker>();

	// TankFactory�I�u�W�F�N�g�𐶐�����
	TankFactory tankFactory(position, angle, color);
	// Body�I�u�W�F�N�g�𐶐����� 
	m_tank = tankFactory.Create(Tank::PARTS_ID::BODY);
	// Turret�I�u�W�F�N�𐶐�����
	Tank* turret = tankFactory.Create(Tank::PARTS_ID::TURRET);
	// Cannon�I�u�W�F�N�𐶐�����
	Tank* cannon = tankFactory.Create(Tank::PARTS_ID::CANNON);
	// Turret�I�u�W�F�N�g��Cannon�I�u�W�F�N�g��ǉ�����
	turret->AddParts(cannon);
	// Body�I�u�W�F�N�g��Turret�I�u�W�F�N�g��ǉ�����
	m_tank->AddParts(turret);
}

// Player�I�u�W�F�N�g���X�V����
bool Player::Update(const DX::StepTimer& timer) 
{
	// �L�[�{�[�h�̏�Ԃ��擾����
	DirectX::Keyboard::State keyboardState = m_keyboard->GetState();
	// �L�[�{�[�h�g���b�J�[���X�V����
	m_keyboardTracker->Update(keyboardState);

	// ���x�����Z�b�g����
	m_tank->SetVelocity(DirectX::SimpleMath::Vector2(0.0f, 0.0f));
	// �E�ɉ�]����
	if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::Right))
	{
		// ��]�p��ݒ肷��
		m_tank->SetBodyAngle(m_tank->GetBodyAngle() - DirectX::XMConvertToRadians(1.0f));
	}
	// ���ɉ�]����
	else if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::Left))
	{
		// ��]�p��ݒ肷��
		m_tank->SetBodyAngle(m_tank->GetBodyAngle() + DirectX::XMConvertToRadians(1.0f));
	}
	// �O�i����
	if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::Up))
	{
		// ��]�s��𐶐�����
		DirectX::SimpleMath::Matrix rotation = DirectX::SimpleMath::Matrix::CreateRotationZ(-m_tank->GetBodyAngle());
		// ���x��ݒ肷��
		m_tank->SetVelocity(DirectX::SimpleMath::Vector2::Transform(Tank::SPEED, rotation));
	}
	// ��ނ���
	else if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::Down))
	{
		// ��]�s��𐶐�����
		DirectX::SimpleMath::Matrix rotation = DirectX::SimpleMath::Matrix::CreateRotationZ(-m_tank->GetBodyAngle());
		// ���x��ݒ肷��
		m_tank->SetVelocity(-DirectX::SimpleMath::Vector2::Transform(Tank::SPEED, rotation));
	}

	// Turret���E�ɉ�]����
	if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::D))
	{
		m_tank->SetTurretAngle(m_tank->GetTurretAngle() - DirectX::XMConvertToRadians(1.0f));
	}
	// Turret�����ɉ�]����
	if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::A))
	{
		m_tank->SetTurretAngle(m_tank->GetTurretAngle() + DirectX::XMConvertToRadians(1.0f));
	}

	// �ړ�����
	m_tank->SetPosition(m_tank->GetPosition() + m_tank->GetVelocity());
	// Tank�I�u�W�F�N�g���X�V����
	m_tank->Update(timer);

	return true;
}

// �X�v���C�g��`�悷��
void Player::Render(DirectX::SpriteBatch& spriteBatch)
{
	// Tank�I�u�W�F�N�g��`�悷��
	m_tank->Render(spriteBatch, m_tank->GetPosition(), m_tank->GetBodyAngle(), m_tank->GetColor());
}

// �㏈���������Ȃ�
void Player::Finalize() 
{
	// �ċA�I��Tank�I�u�W�F�N�g�̌㏈���������Ȃ�
	m_tank->Finalize();	
	// Tank�I�u�W�F�N�g�����Z�b�g����
	if(m_tank != nullptr)
		delete m_tank;
}
