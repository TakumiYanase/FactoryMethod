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
#include "BulletFactory.h"
#include "Bullet.h"

// Playerクラス
class Player
{
public:
	// コンストラクタ
	Player();
	// 初期化する
	void Initialize(DirectX::SimpleMath::Vector2 position,float angle,DirectX::SimpleMath::Vector4 color);
	// 更新する
	bool Update(const DX::StepTimer& timer);
	// 描画する
	void Render(DirectX::SpriteBatch& spriteBatch);
	// 後処理をおこなう
	void Finalize();

private:
	// キーボード 
	std::unique_ptr<DirectX::Keyboard> m_keyboard;
	// キーボードステートトラッカ
	std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> m_keyboardTracker;

	// タンク
	Tank* m_tank;
	// BulletFactoryオブジェクト
	std::unique_ptr<BulletFactory> m_bulletFactory;

	// Bulletオブジェクト配列
	std::vector<Bullet*> m_bullets;
	// Bulletの飛行弾数
	int m_bulletNum;
};

#endif // PLAYER_DEFINED
