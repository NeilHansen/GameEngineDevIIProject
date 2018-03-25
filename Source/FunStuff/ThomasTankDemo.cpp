#include "ThomasTankDemo.h"

void ThomasTankDemo::Initialize()
{
	std::cout << "Demo Manager Initialized" << std::endl;
}

void ThomasTankDemo::Start()
{
	// Create floor
	m_floor = m_sceneGraph->CreateObject(m_assetHolder.miscTexture);
	m_floor->m_Transform->m_Position = Vector2(64.0f, 64.0f);

	// Create player
	//m_player = m_sceneGraph->CreateObject(m_assetHolder.playerTexture);
	//m_player->m_Transform->m_Position = Vector2(0.0f, 0.0f);

	// create other shit

}

void ThomasTankDemo::MovePlayer(Vector2 dir)
{
	m_player->m_RigidBody->AddForce(dir * playerForce);
}


