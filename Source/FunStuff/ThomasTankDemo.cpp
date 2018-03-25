#include "ThomasTankDemo.h"

void ThomasTankDemo::Initialize()
{
	std::cout << "Demo Manager Initialized" << std::endl;
}

void ThomasTankDemo::Start()
{
	// Create floor
	//m_floor = m_sceneGraph->CreateObject(m_assetHolder.playerTexture);
	//m_floor->m_Transform.m_Position = Vector2(100.0f, 100.0f);

	// Create player
	m_player = m_sceneGraph->CreateObject(m_assetHolder.miscTexture);
	m_player->m_Transform->m_Position = Vector2(500.0f, 500.0f);

	// create other shit

}

void ThomasTankDemo::MovePlayer(Vector2 dir)
{
	m_player->m_RigidBody->AddForce(dir * playerForce);
}


