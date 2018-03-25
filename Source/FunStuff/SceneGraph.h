#pragma once
#include <list>
#include <map>
#include "GameObject.h"
#include "ThomasTankDisplay.h"


class SceneGraph
{
public:
	GameObject* CreateObject();

	void Start();
	void Update(sf::Time deltaTime);

	std::list<RenderComponent> GetRenderComponents();

private:
	std::map<int, GameObject*> m_Objects;
	std::list<RenderComponent> renderComponents;
	static int nextObjectID;
};