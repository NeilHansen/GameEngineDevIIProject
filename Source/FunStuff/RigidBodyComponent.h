#ifndef RIGIDBODYCOMPONENT_H
#define RIGIDBODYCOMPONENT_H
#pragma once
#include "GameObject.h"
#include "BaseComponent.h"
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
	float m_mass;
	float m_bounciness;

	bool m_obeysGravity;
	bool m_isGrounded;

	Vector2 m_gravity;

	Vector2 m_currentVelocity;
	Vector2 m_maxVelocity;

	AABB m_AABB;

	GameObject m_owner;

private:
	Vector2 m_totalForces;
	// physics engine ref

public:
	RigidBodyComponent() {}
	RigidBodyComponent(GameObject owner) : m_owner(owner) {};
	~RigidBodyComponent() {}; // I dunno why, but void.....

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
