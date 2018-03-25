#include "SceneGraph.h"

int SceneGraph::nextObjectID = 0;

GameObject* SceneGraph::CreateObject(sf::Texture texture)
{
	std::cout << "Scene Graph is Creating GameObject" << std::endl;

	// Add obj to m_objects and increase the id for the next obj
	GameObject* obj = new GameObject(nextObjectID, texture);
	m_Objects.push_back(obj);
	//m_Objects.insert(std::make_pair(nextObjectID, obj));
	//m_Objects[obj->m_ID] = obj;
	nextObjectID++;

	// add render component to our list (for passing to the display class)
	renderComponents.push_back(obj->m_Render);
	std::cout << "render components size: " << renderComponents.size() << std::endl;

	return obj;
}

void SceneGraph::Start()
{
	for (std::list<GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i)
	{
		(*i)->Start();
	}
}

void SceneGraph::Update(sf::Time deltaTime)
{
	for (std::list<GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i)
	{
		(*i)->Update(deltaTime);
	}
}

std::list<RenderComponent> SceneGraph::GetRenderComponents()
{
	return renderComponents;
}
