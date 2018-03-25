#include "GameObject.h"
//#include "RigidBodyComponent.h"

void GameObject::Start()
{
	m_Transform = TransformComponent();
	m_Render = RenderComponent();
	m_Render.Start();
	m_RigidBody = RigidBodyComponent(m_Transform, m_Render, m_ID);

	// Run children start methods
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
	m_Transform.Update();
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

/*
void GameObject::AddComponent(BaseComponent* component)
{
	m_Components.push_back(component);
}
*/


