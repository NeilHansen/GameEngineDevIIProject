#pragma once
#include "Vector2.h"
#include "RigidBodyComponent.h"

#include <list>
#include <map>

struct CollisionPair
{
public:
	RigidBodyComponent rigidBodyA;
	RigidBodyComponent rigidBodyB;

	bool operator==(const CollisionPair& cp) const
	{
		return (rigidBodyA.m_owner.m_ID == cp.rigidBodyA.m_owner.m_ID && rigidBodyB.m_owner.m_ID == cp.rigidBodyB.m_owner.m_ID);
	}
	bool operator<(const CollisionPair& cp) const
	{
		return (rigidBodyA.m_owner.m_ID < cp.rigidBodyA.m_owner.m_ID || rigidBodyB.m_owner.m_ID < cp.rigidBodyB.m_owner.m_ID);
	}
	bool operator!=(const CollisionPair& cp) const { return !operator==(cp); }
	bool operator> (const CollisionPair& cp) const { return  operator< (cp); }
	bool operator<=(const CollisionPair& cp) const { return !operator> (cp); }
	bool operator>=(const CollisionPair& cp) const { return !operator< (cp); }
};


struct CollisionInfo
{
public:
	float penetration;
	Vector2 collisionNormal;
};


class ThomasTankPhysics
{
public:

private:
	static float groundedTolerance;

	static std::map<CollisionPair, CollisionInfo> collisions;
	static std::list<RigidBodyComponent> rigidBodies;

	static int rigidBodyCount;

public:
	ThomasTankPhysics();
	~ThomasTankPhysics();

	static void Initialize();
	static void FixedUpdate(float dt);	

	static void AddRigidBody(RigidBodyComponent rb);
	static bool IsGrounded(RigidBodyComponent rb);

private:
	static void CheckCollisions();
	static void ResolveCollisions();
	static void PositionalCorrection(CollisionPair c);
	static void IntegrateBodies(float dt);

};