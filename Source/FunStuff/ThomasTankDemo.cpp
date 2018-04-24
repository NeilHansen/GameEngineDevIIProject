#include "ThomasTankDemo.h"

void ThomasTankDemo::Initialize()
{
	std::cout << "Demo Manager Initialized" << std::endl;
}

void ThomasTankDemo::Start()
{
	isChanged = true;
	is2Changed = true;
	// Create floor
	//m_floor = m_sceneGraph->CreateObject(m_assetHolder.miscTexture, true, Vector2(300.0f, 500.0f));
	//m_floor->m_Transform->m_Position = ;

	// Create player
	m_player = m_sceneGraph->CreateObject(m_assetHolder.playerTexture, false, Vector2(100.0f, (m_mainDisplay.mainWindow.getSize().y) / 2.0f));
	m_player->m_RigidBody->m_mass = 10.0f;

	m_player2 = m_sceneGraph->CreateObject(m_assetHolder.enemyTexture, false, Vector2((m_mainDisplay.mainWindow.getSize().x) - 100.0f, (m_mainDisplay.mainWindow.getSize().y) / 2.0f));
	m_player2->m_RigidBody->m_mass = 10.0f;

	//GameObject* test = m_sceneGraph->CreateObject(m_assetHolder.playerTexture, false, Vector2(230.0f, 100.0f));

	//m_player->AddChild(test);
	//test->m_Transform->m_Position = Vector2(240.0f, 0.0f);
	// create other shit

}

void ThomasTankDemo::MovePlayer(Vector2 dir, bool isFirstPlayer)
{
	if (isFirstPlayer)
	{
		//std::cout << "Add Force" << std::endl;
		m_player->m_RigidBody->AddForce(dir * playerForce);
	}
	else
	{
		m_player2->m_RigidBody->AddForce(dir * playerForce);
	}
}

void ThomasTankDemo::StopPlayer(bool isFirstPlayer)
{
	if (isFirstPlayer)
	{
		m_player->m_RigidBody->Stop();
	}
	else
	{
		m_player2->m_RigidBody->Stop();
	}
}

void ThomasTankDemo::WalkingSprite(bool isWalking, bool isFirstPlayer)
{
	if (isFirstPlayer)
	{
		if (isWalking)
		{
			if (isChanged) 
			{
				isChanged = false;
				m_player->m_Render->m_texture = ThomasTankDemo::m_assetHolder.playerWalkTexture;
			}
			else if(!isChanged){
				isChanged = true;
				m_player->m_Render->m_texture = ThomasTankDemo::m_assetHolder.playerTexture;
			}

			std::cout << "Player 1 Walking............................................." << std::endl;
		}
		else
		{
			m_player->m_Render->m_texture = ThomasTankDemo::m_assetHolder.playerTexture;
			std::cout << "Player 1 IDLE............................................." << std::endl;
		}
	}
	else
	{
		if (isWalking)
		{
			if (is2Changed)
			{
				is2Changed = false;
				m_player2->m_Render->m_texture = ThomasTankDemo::m_assetHolder.enemyWalkTexture;
			}
			else if (!is2Changed) 
			{
				is2Changed = true;
				m_player2->m_Render->m_texture = ThomasTankDemo::m_assetHolder.enemyTexture;
			}

			std::cout << "Player 2 Walking............................................." << std::endl;
		}
		else
		{
			m_player2->m_Render->m_texture = ThomasTankDemo::m_assetHolder.enemyTexture;

			std::cout << "Player 2 IDLE............................................." << std::endl;
		}

	}
}

void ThomasTankDemo::ShootingSprite(bool isFirstPlayer)
{
	if (isFirstPlayer)
	{
		ThomasTankInput::canMove = false;
		m_player->m_Render->m_texture = ThomasTankDemo::m_assetHolder.playerShootTexture;
		std::cout << "Player 1 Firing............................................." << std::endl;
		m_bullet = m_sceneGraph->CreateObject(m_assetHolder.miscTexture, false, Vector2(m_player->m_Transform->m_Position.x, m_player->m_Transform->m_Position.y));
		m_bullet->m_RigidBody->m_mass = 10.0f;
		MoveBullet(true);
		//set delay here too
	}
	else
	{
		ThomasTankInput::canMove = false;
		m_player2->m_Render->m_texture = ThomasTankDemo::m_assetHolder.enemyShootTexture;
		std::cout << "Player 2 Firing............................................." << std::endl;
		m_bullet2 = m_sceneGraph->CreateObject(m_assetHolder.miscTexture, false, Vector2(m_player2->m_Transform->m_Position.x, m_player2->m_Transform->m_Position.y));
		m_bullet2->m_RigidBody->m_mass = 10.0f;
		//set delay here too
	}
}

void ThomasTankDemo::DeathSprite(bool isFirstPlayer)
{
	if (isFirstPlayer)
	{
		ThomasTankInput::canMove = false;
		m_player->m_Render->m_texture = ThomasTankDemo::m_assetHolder.playerHitTexture;
		//	m_player->m_Render->m_texture(ThomasTankDemo::m_assetHolder.playerWalkTexture);
		std::cout << "Player 1 Dead............................................." << std::endl;
		//set delay here too
	}
	else
	{
		ThomasTankInput::canMove = false;
		m_player2->m_Render->m_texture = ThomasTankDemo::m_assetHolder.enemyHitTexture;
		//	m_player2->m_Render->m_texture.swap(ThomasTankDemo::m_assetHolder.enemyWalkTexture);
		std::cout << "Player 2 Dead............................................" << std::endl;
		//set delay here too
	}
}

void ThomasTankDemo::MoveBullet(bool isFirstPlayer)
{
	if (isFirstPlayer)
	{
		//std::cout << "Add Force" << std::endl;
		do {
			m_bullet->m_RigidBody->AddForce(Vector2(3.0f, 0.0f));
		} while (m_bullet->m_Transform->m_Position.x <= (m_mainDisplay.mainWindow.getSize().x) - 100.0f);
		if ((m_bullet->m_Transform->m_Position.x <= (m_mainDisplay.mainWindow.getSize().x) - 100.0f)) 
		{
			MoveSprite();
			ThomasTankInput::WalkingAnim(false, false);
		}
	}
	else
	{
		m_bullet2->m_RigidBody->AddForce(Vector2(-3.0f, 0.0f));
	}
}

void ThomasTankDemo::MoveSprite()
{
	ThomasTankInput::canMove = true;
}