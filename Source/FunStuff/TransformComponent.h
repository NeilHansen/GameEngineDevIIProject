#pragma once

#include "SFML/Graphics/Transform.hpp"
#include "BaseComponent.cpp"

struct Vector2
{
public:
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float X, float Y) : x(X), y(Y) {}

	float x, y;
};

class TransformComponent : BaseComponent
{
public:
	TransformComponent() : m_Position(), m_Rotation(), m_Scale(1.0f, 1.0f) {}
	
	void Start();
	void Update(float deltaTime);

	sf::Transform transformMatrix;
	Vector2 m_Position;
	Vector2 m_Rotation;
	Vector2 m_Scale;
};