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
	static void PositionalCorrection();
	static void IntegrateBodies(float dt);

};