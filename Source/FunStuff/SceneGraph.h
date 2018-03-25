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

	std::list<RenderComponent> GetRenderComponents();
	std::list<RenderComponent> renderComponents;
	std::list<GameObject*> m_Objects = std::list<GameObject*>();

private:
	
	
	static int nextObjectID;
};