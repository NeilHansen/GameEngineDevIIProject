#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#pragma once
//#include "GameObject.h"
#include "BaseComponent.h"
#include "Vector2.h"

#include "SFML/Graphics/Sprite.hpp"

class GameObject;

// TODO create bounds for sprite
// UNITY: This is the axis-aligned bounding box fully enclosing the object in world space.
struct Bounds
{
public:
	Vector2 center;
	Vector2 extents; // 0-1 values?
};

class RenderComponent:BaseComponent
{
public:
	sf::Sprite m_sprite;
	Bounds m_bounds;
	
	//GameObject m_owner;

	RenderComponent() {}
	//RenderComponent(GameObject owner, sf::Sprite sprite) : m_owner(owner), m_sprite(sprite) {}
	~RenderComponent() {}
};

#endif // !RENDERCOMPONENT_H