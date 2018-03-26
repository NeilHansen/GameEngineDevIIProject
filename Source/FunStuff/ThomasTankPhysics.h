#ifndef THOMASTANKPHYSICS_H
#define THOMASTANKPHYSICS_H
#pragma once
#include "Vector2.h"
#include "CollisionPair.h"

#include <list>
#include <map>

class RigidBodyComponent; //forward declration

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
	static std::list<RigidBodyComponent*> rigidBodies;

	static int rigidBodyCount;

public:
	ThomasTankPhysics() {}
	~ThomasTankPhysics() {}

	static void Initialize();
	static void FixedUpdate(float dt);	

	static void AddRigidBody(RigidBodyComponent* rb);
	static bool IsGrounded(RigidBodyComponent* rb);

private:
	static void CheckCollisions();
	static void ResolveCollisions();
	static void PositionalCorrection(CollisionPair c);
	static void IntegrateBodies(float dt);

};

#endif RIGIDBODYCOMPONENT_H