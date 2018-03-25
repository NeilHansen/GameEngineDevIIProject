#include "SceneGraph.h"

int SceneGraph::nextObjectID = 0;


GameObject* SceneGraph::CreateObject()
{
	// Add obj to m_objects and increase the id for the next obj
	GameObject* obj = new GameObject(nextObjectID);
	m_Objects[obj->GetObjID()] = obj;
	nextObjectID++;

	// add render component to our list (for passing to the display class)
	renderComponents.push_back(obj->m_Render);

	return obj;
}

void SceneGraph::Start()
{
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i)
	{
		(i->second)->Start();
	}
}

void SceneGraph::Update(sf::Time deltaTime)
{
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i)
	{
		(i->second)->Update(deltaTime);
	}
}

std::list<RenderComponent> SceneGraph::GetRenderComponents()
{
	return renderComponents;
}
