#pragma once

#include "Vector2.h"
#include "SceneGraph.h"
#include "ThomasTankAssetHolder.h"

class ThomasTankDemo
{
public:
	float playerForce = 100.0f;

private:
	SceneGraph* m_sceneGraph;
	ThomasTankAssetHolder m_assetHolder;

	GameObject* m_player;
	GameObject* m_player2;
	GameObject* m_floor;

public:
	ThomasTankDemo() {}
	ThomasTankDemo(SceneGraph* sg, ThomasTankAssetHolder ah) : m_sceneGraph(sg), m_assetHolder(ah) {}
	~ThomasTankDemo() {}

	void Initialize();
	void Start(); // create gameobjects for demo

	void MovePlayer(Vector2 dir, bool isFirstPlayer); // called from input - adds force to our player ref's rigidbody

	void StopPlayer(bool isFirstPlayer);

private:
	
};