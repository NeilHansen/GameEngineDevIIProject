#ifndef RIGIDBODYCOMPONENT_H
#define RIGIDBODYCOMPONENT_H
#pragma once
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "Vector2.h"

class ThomasTankPhysics;
//class GameObject;

struct AABB
{
public:
	Vector2 bLeft;
	Vector2 tRight;
};

class RigidBodyComponent:BaseComponent
{
public:
	float m_mass = 1.0f;
	float m_bounciness;

	bool m_isKinematic;
	bool m_isGrounded;

	Vector2 m_gravity;

	Vector2 m_currentVelocity;
	Vector2 m_maxVelocity;

	AABB m_AABB;

	int m_Id;
	
	TransformComponent* m_ownerTransform;
	RenderComponent* m_ownerRenderer;

private:
	Vector2 m_totalForces;

public:
	RigidBodyComponent() {}
	RigidBodyComponent(TransformComponent* transform, RenderComponent* renderer, bool isKinematic, int id) : m_ownerTransform(transform), m_ownerRenderer(renderer), m_isKinematic(isKinematic), m_Id(id) {};
	~RigidBodyComponent() {};

	void Start();
	// Update removed - is updated by physics engine

	void AddForce(Vector2 force);
	void Stop();

	void SetAABB();
	void Integrate(float dt);

	bool IsGrounded();
private:
	
};

#endif
