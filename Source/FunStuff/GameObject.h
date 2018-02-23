#pragma once

#include <list>
#include <vector>
#include <iterator>

#include <SFML/System/Clock.hpp>

#include "BaseComponent.h"
#include "TransformComponent.h"


class GameObject
{
public:
	GameObject(int objID) : m_ID(objID), m_Parent(NULL) {}

	// Get/Set
	int GetObjID() { return m_ID; }

	void SetParent(GameObject& parent);
	void AddChild(GameObject* child);

	void AddComponent(BaseComponent* component);

	void Start();
	void Update(sf::Time deltaTime);
	
	TransformComponent m_Transform;

private:
	int m_ID;

	GameObject* m_Parent;
	std::vector<GameObject*> m_Children;

	sf::Transform identityMatrix;
	sf::Transform worldTransform;

	std::vector<BaseComponent*> m_Components;
};