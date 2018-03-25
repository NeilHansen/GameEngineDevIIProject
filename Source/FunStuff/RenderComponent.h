#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#pragma once
//#include "GameObject.h"
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "Vector2.h"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"


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
	sf::Texture m_texture;
	Bounds m_bounds;
	TransformComponent m_ownerTransform;

private:
	sf::Sprite m_sprite;

public:
	RenderComponent() {}
	RenderComponent(TransformComponent ownerTransform, sf::Texture texture) : m_ownerTransform(ownerTransform), m_texture(texture) {}
	~RenderComponent() {}

	void Start();
	void Draw();

private:
	void SetBounds();
};

#endif // !RENDERCOMPONENT_H