#pragma once
#include <map>
#include "GameObject.h"


class SceneGraph
{
public:
	GameObject* CreateObject();

	void Start();
	void Update(sf::Time deltaTime);

private:
	std::map<int, GameObject*> m_Objects;
	static int nextObjectID;
};