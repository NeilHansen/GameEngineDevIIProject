#include "ThomasTankDemo.h"

void ThomasTankDemo::Initialize()
{
	std::cout << "Demo Manager Initialized" << std::endl;
}

void ThomasTankDemo::Start()
{
	// Create floor
	m_floor = m_sceneGraph->CreateObject(m_assetHolder.miscTexture, true, Vector2(300.0f, 500.0f));
	//m_floor->m_Transform->m_Position = ;

	// Create player
	m_player = m_sceneGraph->CreateObject(m_assetHolder.playerTexture, false, Vector2(300.0f, 0.0f));
	//m_player->m_Transform->m_Position = ;

	GameObject* test = m_sceneGraph->CreateObject(m_assetHolder.playerTexture, false, Vector2(150.0f, 0.0f));
	//test->m_Transform->m_Position = Vector2(240.0f, 0.0f);
	// create other shit

}

void ThomasTankDemo::MovePlayer(Vector2 dir)
{
	m_player->m_RigidBody->AddForce(dir * playerForce);
}


