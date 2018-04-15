#include "ThomasTankDemo.h"

void ThomasTankDemo::Initialize()
{
	std::cout << "Demo Manager Initialized" << std::endl;
}

void ThomasTankDemo::Start()
{
	// Create floor
	//m_floor = m_sceneGraph->CreateObject(m_assetHolder.miscTexture, true, Vector2(300.0f, 500.0f));
	//m_floor->m_Transform->m_Position = ;

	// Create player
	m_player = m_sceneGraph->CreateObject(m_assetHolder.playerTexture, false, Vector2(100.0f, 200.0f));
	m_player->m_RigidBody->m_mass = 10.0f;

	m_player2 = m_sceneGraph->CreateObject(m_assetHolder.enemyTexture, false, Vector2(400.0f, 200.0f));
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
			//	m_player->m_Render->m_texture(ThomasTankDemo::m_assetHolder.playerWalkTexture);

			std::cout << "Player 1 Walking............................................." << std::endl;

		}
		else
		{
			//m_player->m_Render->m_texture.swap(ThomasTankDemo::m_assetHolder.playerTexture);
			std::cout << "Player 1 IDLE............................................." << std::endl;
		}
	}
	else
	{
		if (isWalking)
		{
			//	m_player2->m_Render->m_texture.swap(ThomasTankDemo::m_assetHolder.enemyWalkTexture);
			std::cout << "Player 2 Walking............................................." << std::endl;
		}
		else
		{
			//	m_player2->m_Render->m_texture.swap(ThomasTankDemo::m_assetHolder.enemyWalkTexture);
			std::cout << "Player 2 IDLE............................................." << std::endl;
		}

	}
}

void ThomasTankDemo::ShootingSprite(bool isFirstPlayer)
{
	if (isFirstPlayer)
	{
		//	m_player->m_Render->m_texture(ThomasTankDemo::m_assetHolder.playerWalkTexture);
		std::cout << "Player 1 Firing............................................." << std::endl;
		//set delay here too
	}
	else
	{
		//	m_player2->m_Render->m_texture.swap(ThomasTankDemo::m_assetHolder.enemyWalkTexture);
		std::cout << "Player 2 Firing............................................." << std::endl;
		//set delay here too
	}
}

void ThomasTankDemo::DeathSprite(bool isFirstPlayer)
{
	if (isFirstPlayer)
	{
		//	m_player->m_Render->m_texture(ThomasTankDemo::m_assetHolder.playerWalkTexture);
		std::cout << "Player 1 Dead............................................." << std::endl;
		//set delay here too
	}
	else
	{
		//	m_player2->m_Render->m_texture.swap(ThomasTankDemo::m_assetHolder.enemyWalkTexture);
		std::cout << "Player 2 Dead............................................" << std::endl;
		//set delay here too
	}
}