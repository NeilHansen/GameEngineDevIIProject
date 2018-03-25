#include "RenderComponent.h"

// draw the sprite at the owner's tranform's position
void RenderComponent::Draw() // name: Update()?
{
	// set the sprite's position to our owner's transform's position
	m_sprite.setPosition(m_ownerTransform.m_Position.x, m_ownerTransform.m_Position.y);
}

void RenderComponent::Start()
{
	// initialize sprite object(sf::drawable & sf::transformable)
	//x get texture
	//x get rect of texture to assign for sprite (let's just use single images for everything...)
	m_sprite = sf::Sprite(m_texture); // create sprite

	// Set our sprite's bounds
	SetBounds();

	// set the sprite's position to our owner's transform's position
	m_sprite.setPosition(m_ownerTransform.m_Position.x, m_ownerTransform.m_Position.y);
}

// Set this component's bounds to the size of its sprite's global bounds
void RenderComponent::SetBounds()
{
	
	sf::Rect<float> r = m_sprite.getGlobalBounds();

	m_bounds.center = Vector2(m_sprite.getOrigin().x, m_sprite.getOrigin().y);
	m_bounds.extents = Vector2(r.width * 0.5, r.height * 0.5);
}
