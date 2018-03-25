#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#pragma once
#include <list>
#include <vector>
#include <iterator>

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Vector2.h"
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "RigidBodyComponent.h"


class GameObject
{
public:
	GameObject() {}
	GameObject(int objID, sf::Texture texture) : m_ID(objID), m_Parent(NULL), m_texture(texture) {}

	// Get/Set
	int GetObjID() { return m_ID; }

	void SetParent(GameObject& parent);
	void AddChild(GameObject* child);

	void Start();
	void Update(sf::Time deltaTime);
	
	TransformComponent m_Transform;
	RigidBodyComponent m_RigidBody;
	RenderComponent m_Render;

	int m_ID; // made this public for physics component, can remove GetObjID()

private:
	GameObject* m_Parent;
	std::vector<GameObject*> m_Children;

	sf::Transform identityMatrix;
	sf::Transform worldTransform;

	sf::Texture m_texture;
};

#endif