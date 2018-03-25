#pragma once
#include <list>
#include <map>
#include <iostream>

#include "GameObject.h"


class SceneGraph
{
public:
	GameObject* CreateObject(sf::Texture texture);

	void Start();
	void Update(sf::Time deltaTime);

	std::list<RenderComponent*> renderComponents;

private:
	std::map<int, GameObject*> m_Objects;
	static int nextObjectID;
};