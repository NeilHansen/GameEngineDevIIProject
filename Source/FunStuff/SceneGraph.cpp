#include "SceneGraph.h"

int SceneGraph::nextObjectID = 0;

GameObject* SceneGraph::CreateObject(sf::Texture texture, bool isKinematic, Vector2 pos)
{
	std::cout << "Scene Graph is Creating GameObject" << std::endl;

	// Add obj to m_objects and increase the id for the next obj
	GameObject* obj = new GameObject(nextObjectID, texture, isKinematic, pos);
	m_Objects.insert(std::make_pair(nextObjectID, obj));
	//m_Objects[obj->m_ID] = obj;
	nextObjectID++;

	// Add render component to our list (for passing to the display class)
	renderComponents.push_back(obj->m_Render);
	//std::cout << "render components size: " << renderComponents.size() << std::endl;

	// Pass rb component to physics engine
	ThomasTankPhysics::AddRigidBody(obj->m_RigidBody);

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

