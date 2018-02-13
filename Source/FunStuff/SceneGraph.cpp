#include "SceneGraph.h"

GameObject::GameObject() {
	parent = NULL;
}

GameObject::~GameObject(void) {
	for (unsigned int i = 0; i < children.size(); i++){
		delete children[i];
	}
}

void GameObject::AddChild(GameObject* s) {
	children.push_back(s);
	s->parent = this;
}

void GameObject::Initialize()
{
	GameObject();
	std::cout << "SceneGraph Initialized" << "\n";
}

void GameObject::Update(float msec) {
	if (parent) {
		worldTransform = parent->worldTransform * transform;
	}
	else {
		worldTransform = transform;
	}

	for (std::vector<GameObject*>::iterator i = children.begin(); i != children.end(); ++i) {
		(*i)->Update(msec);
	}
}