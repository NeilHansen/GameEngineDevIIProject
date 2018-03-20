#include "GameObject.h"
#include "RigidBodyComponent.h"

void GameObject::Start()
{
	// Run components/children start methods
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i)
	{
		(*i)->Start();
	}
	for (std::vector<GameObject*>::iterator i = m_Children.begin(); i != m_Children.end(); ++i)
	{
		(*i)->Start();
	}
}

void GameObject::Update(sf::Time deltaTime)
{
	// Update position relative to parent
	if (m_Parent)
	{
		worldTransform = m_Parent->worldTransform * m_Transform.transformMatrix;
	}
	// This is the root GameObject
	else
	{
		worldTransform = m_Transform.transformMatrix;
	}

	// Run components/children update methods
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i)
	{
		(*i)->Update();
	}
	for (std::vector<GameObject*>::iterator i = m_Children.begin(); i != m_Children.end(); ++i)
	{
		(*i)->Update(deltaTime);
	}
}

void GameObject::SetParent(GameObject& parent)
{
	m_Parent = &parent;
}

void GameObject::AddChild(GameObject* child)
{
	m_Children.push_back(child);
}

void GameObject::AddComponent(BaseComponent* component)
{
	m_Components.push_back(component);
}


