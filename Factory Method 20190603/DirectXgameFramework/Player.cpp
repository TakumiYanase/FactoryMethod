#include "Player.h"

// コンストラクタ
Player::Player()
{
}

// 初期化する
void Player::Initialize(DirectX::SimpleMath::Vector2 position, float angle,DirectX::SimpleMath::Vector4 color)
{
	// Keyboardオブジェクトを生成する
	m_keyboard = std::make_unique<DirectX::Keyboard>();
	// KeyboardStateTrackerオブジェクトを生成する
	m_keyboardTracker = std::make_unique<DirectX::Keyboard::KeyboardStateTracker>();

	// TankFactoryオブジェクトを生成する
	TankFactory tankFactory(position, angle, color);
	// Bodyオブジェクトを生成する 
	m_tank = tankFactory.Create(Tank::PARTS_ID::BODY);
	// Turretオブジェクを生成する
	Tank* turret = tankFactory.Create(Tank::PARTS_ID::TURRET);
	// Cannonオブジェクを生成する
	Tank* cannon = tankFactory.Create(Tank::PARTS_ID::CANNON);
	// TurretオブジェクトにCannonオブジェクトを追加する
	turret->AddParts(cannon);
	// BodyオブジェクトにTurretオブジェクトを追加する
	m_tank->AddParts(turret);
	// 事前に弾を配列分生成するため、コンストラクタに発射する弾の位置、本体回転角、龐統回転角を設定できない
	m_bulletFactory = std::make_unique<BulletFactory>();
	// BulletのInitialize
	m_bulletFactory->Initialize();

	m_bullets.resize(BulletFactory::BULLET_NUM);

	for (int i = 0; i < BulletFactory::BULLET_NUM; i++)
	{
		m_bullets[i] = new Bullet();
	}
	//飛んでる弾0
	m_bulletNum = 0;
}

// Playerオブジェクトを更新する
bool Player::Update(const DX::StepTimer& timer)
{
	// キーボードの状態を取得する
	DirectX::Keyboard::State keyboardState = m_keyboard->GetState();
	// キーボードトラッカーを更新する
	m_keyboardTracker->Update(keyboardState);

	// 速度をリセットする
	m_tank->SetVelocity(DirectX::SimpleMath::Vector2(0.0f, 0.0f));
	// 右に回転する
	if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::Right))
	{
		// 回転角を設定する
		m_tank->SetBodyAngle(m_tank->GetBodyAngle() - DirectX::XMConvertToRadians(1.0f));
	}
	// 左に回転する
	else if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::Left))
	{
		// 回転角を設定する
		m_tank->SetBodyAngle(m_tank->GetBodyAngle() + DirectX::XMConvertToRadians(1.0f));
	}
	// 前進する
	if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::Up))
	{
		// 回転行列を生成する
		DirectX::SimpleMath::Matrix rotation = DirectX::SimpleMath::Matrix::CreateRotationZ(-m_tank->GetBodyAngle());
		// 速度を設定する
		m_tank->SetVelocity(DirectX::SimpleMath::Vector2::Transform(Tank::SPEED, rotation));
	}
	// 後退する
	else if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::Down))
	{
		// 回転行列を生成する
		DirectX::SimpleMath::Matrix rotation = DirectX::SimpleMath::Matrix::CreateRotationZ(-m_tank->GetBodyAngle());
		// 速度を設定する
		m_tank->SetVelocity(-DirectX::SimpleMath::Vector2::Transform(Tank::SPEED, rotation));
	}

	if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::D))
	{
		// 回転角を設定する
		m_tank->SetTurretAngle(m_tank->GetTurretAngle() - DirectX::XMConvertToRadians(1.0f));
	}
	// 左に回転する
	else if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::A))
	{
		// 回転角を設定する
		m_tank->SetTurretAngle(m_tank->GetTurretAngle() + DirectX::XMConvertToRadians(1.0f));
	}

	// 移動する
	m_tank->SetPosition(m_tank->GetPosition() + m_tank->GetVelocity());
	// Tankオブジェクトを更新する
	m_tank->Update(timer);

	if (keyboardState.IsKeyDown(DirectX::Keyboard::Keys::Space))
	{
		DirectX::SimpleMath::Vector2 offset = DirectX::SimpleMath::Vector2(64, 0);

		DirectX::SimpleMath::Matrix rotation = DirectX::SimpleMath::Matrix::CreateRotationZ(-m_tank->GetBodyAngle() - m_tank->GetTurretAngle());

		DirectX::SimpleMath::Vector2 position = m_tank->GetPosition() + DirectX::SimpleMath::Vector2::Transform(offset, rotation);

		if (timer.GetFrameCount() % 5 == 0)
		{
			for (int i = 0; i < BulletFactory::BULLET_NUM; i++)
			{
				if (m_bullets[i] == nullptr)
				{
					m_bullets[i] = m_bulletFactory->Create(position, -m_tank->GetBodyAngle() - m_tank->GetTurretAngle());
					m_bulletNum++;
					break;
				}

				else if (m_bullets[i]->IsUsed() == false)
				{
					m_bullets[i] = m_bulletFactory->Create(position, -m_tank->GetBodyAngle() - m_tank->GetTurretAngle());
					break;
				}
			}
		}
	}

	for (int i = 0; i < BulletFactory::BULLET_NUM; i++)
	{
		if (m_bullets[i]->IsUsed())
		{
			m_bullets[i]->Update(timer);
		}
	}

	int regionMin = 0 - Bullet::SIZE / 2;
	int regionMaxWidth = 800;
	int regionMaxHeight = 600;

	for (int i = 0; i < BulletFactory::BULLET_NUM; i++)
	{
		int bulletX = (int)m_bullets[i]->GetPosition().x;
		int bulletY = (int)m_bullets[i]->GetPosition().y;

		if (bulletX < regionMin || bulletY < regionMin || bulletX > regionMaxWidth || bulletY > regionMaxHeight)
		{
			m_bullets[i]->IsUsed(false);
		}
	}
	return true;
}

// スプライトを描画する
void Player::Render(DirectX::SpriteBatch& spriteBatch)
{
	// Tankオブジェクトを描画する
	m_tank->Render(spriteBatch, m_tank->GetPosition(), m_tank->GetBodyAngle(), m_tank->GetColor());

	for (int i = 0; i < BulletFactory::BULLET_NUM; i++)
	{
		if (m_bullets[i]->IsUsed())
		{
			m_bullets[i]->Render(spriteBatch);
		}
	}
}

// 後処理をおこなう
void Player::Finalize()
{
	// 再帰的にTankオブジェクトの後処理をおこなう
	m_tank->Finalize();
	// Tankオブジェクトをリセットする
	if (m_tank != nullptr)
		delete m_tank;
}
