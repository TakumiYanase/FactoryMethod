#pragma once
#ifndef PLAYER_DEFINED
#define PLAYER_DEFINED

#include <d3d11_1.h>
#include <DirectXMath.h>
#include <SimpleMath.h>
#include <Keyboard.h>

#include "StepTimer.h"
#include "dx.h"

#include "DirectX11.h"
#include "TankFactory.h"
#include "ITank.h"
#include "Tank.h"
#include "Turret.h"
#include "Body.h"
#include "Cannon.h"

// Player�N���X
class Player 
{
public:
	// �R���X�g���N�^
	Player();
	// ����������
	void Initialize(DirectX::SimpleMath::Vector2 position, float angle,DirectX::SimpleMath::Vector4 color);
	// �X�V����
	bool Update(const DX::StepTimer& timer);
	// �`�悷��
	void Render(DirectX::SpriteBatch& spriteBatch);
	// �㏈���������Ȃ�
	void Finalize();

private:
	// �e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	// �L�[�{�[�h 
	std::unique_ptr<DirectX::Keyboard> m_keyboard;
	// �L�[�{�[�h�X�e�[�g�g���b�J
	std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> m_keyboardTracker;

	// �^���N
	Tank* m_tank;
};

#endif // PLAYER_DEFINED