#include "TransformComponent.h"

#include <iostream>

void TransformComponent::Start()
{

}

void TransformComponent::Update()
{
	std::cout << "Pos (x: " << m_Position.x << ", y: " << m_Position.y << ")" << std::endl;
}