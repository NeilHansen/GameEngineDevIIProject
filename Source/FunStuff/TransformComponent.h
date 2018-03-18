#pragma once

#include "SFML/Graphics/Transform.hpp"
#include "BaseComponent.cpp"
#include "Vector2.h"

class TransformComponent : BaseComponent
{
public:
	TransformComponent() : m_Position(), m_Rotation(), m_Scale(1.0f, 1.0f) {}
	
	void Start();
	void Update();

	sf::Transform transformMatrix;
	Vector2 m_Position;
	Vector2 m_Rotation;
	Vector2 m_Scale;
};