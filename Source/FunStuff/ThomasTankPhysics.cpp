#include "ThomasTankPhysics.h"
#include "RigidBodyComponent.h"
#include <cmath>
#include <iostream>

float ThomasTankPhysics::groundedTolerance;

std::map<CollisionPair, CollisionInfo> ThomasTankPhysics::collisions;
std::list<RigidBodyComponent> ThomasTankPhysics::rigidBodies;

ThomasTankPhysics::ThomasTankPhysics()
{
}

ThomasTankPhysics::~ThomasTankPhysics()
{
}

void ThomasTankPhysics::FixedUpdate(float dt)
{
	IntegrateBodies(dt);
	CheckCollisions();
	ResolveCollisions();
}

void ThomasTankPhysics::Initialize()
{
	// Initialize values
	groundedTolerance = 0.1f;

	std::cout << "Physics Engine Initialized" << "\n";
}

void ThomasTankPhysics::AddRigidBody(RigidBodyComponent rb)
{
	rigidBodies.assign(1, rb);
}

bool ThomasTankPhysics::IsGrounded(RigidBodyComponent rb)
{
	// traverse rigid bodies
	for (std::list<RigidBodyComponent>::iterator it = rigidBodies.begin(); it != rigidBodies.end(); it++)
	{
		// check the rb passed agains't all other rbs
		if (it->m_Id != rb.m_Id)
		{
			// check if the rb is ontop of another object
			if (rb.m_AABB.bLeft.x < it->m_AABB.tRight.x &&
				rb.m_AABB.tRight.x > it->m_AABB.bLeft.x &&
				abs(rb.m_AABB.bLeft.y - it->m_AABB.tRight.y) <= groundedTolerance)
			{
				// check if the absolute value of the rb's current vel (y) is less than the ground tolerance
				if (abs(rb.m_currentVelocity.y) < groundedTolerance)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void ThomasTankPhysics::IntegrateBodies(float dt)
{
	for (std::list<RigidBodyComponent>::iterator it = rigidBodies.begin(); it != rigidBodies.end(); it++)
	{
		it->Integrate(dt);
	}
}

void ThomasTankPhysics::CheckCollisions()
{
	// Get the second last element of our rigidbody list
	auto secondLastElement = rigidBodies.end();
	std::advance(secondLastElement, -1);

	// Traverse all rigidbodies except the last
	for (std::list<RigidBodyComponent>::iterator bodyA = rigidBodies.begin(); bodyA != secondLastElement; bodyA++)
	{
		// find the index of body a
		auto remainingElements = rigidBodies.end();
		std::advance(remainingElements, std::distance(bodyA, rigidBodies.end()));

		for (std::list<RigidBodyComponent>::iterator bodyB = rigidBodies.begin(); bodyB != remainingElements; bodyB++)
		{
			CollisionPair colPair = CollisionPair();
			CollisionInfo colInfo = CollisionInfo();
			colPair.rigidBodyA = *bodyA;
			colPair.rigidBodyB = *bodyB;
			Vector2 distance = Vector2::Distance(bodyA->m_ownerTransform.m_Position, bodyB->m_ownerTransform.m_Position);

			Vector2 disA = Vector2::Distance(bodyA->m_AABB.tRight, bodyA->m_AABB.bLeft);
			Vector2 halfSizeA = Vector2(disA.x * 0.5f, disA.y * 0.5f);

			Vector2 disB = Vector2::Distance(bodyB->m_AABB.tRight, bodyB->m_AABB.bLeft);
			Vector2 halfSizeB = Vector2(disB.x * 0.5f, disB.y * 0.5f);
			
			Vector2 gap = Vector2::Distance(Vector2(abs(distance.x), abs(distance.y)), Vector2(halfSizeA.x + halfSizeB.x, halfSizeA.y + halfSizeB.y));

			std::map<CollisionPair, CollisionInfo>::iterator it = collisions.find(colPair);

			if (gap.x < 0 && gap.y < 0)
			{
				std::cout << "Objects collided!!" << std::endl;
				
				std::map<CollisionPair, CollisionInfo>::iterator it = collisions.find(colPair);
				if (collisions.end() != it)
				{
					collisions.erase(colPair); // remove collision pair
				}

				if (gap.x > gap.y)
				{
					if (distance.x > 0)
					{
						colInfo.collisionNormal = Vector2(1.0f, 0.0f); // right
					}
					else
					{
						colInfo.collisionNormal = Vector2(-1.0f, 0.0f); // left
					}
					colInfo.penetration = gap.x;
				}
				else
				{
					if (distance.y > 0)
					{
						colInfo.collisionNormal = Vector2(0.0f, 1.0f); // up
					}
					else
					{
						colInfo.collisionNormal = Vector2(0.0f, -1.0f); // down
					}
					colInfo.penetration = gap.y;
				}
				collisions.insert(std::make_pair(colPair, colInfo));
			}
			else if (collisions.end() != it)
			{
				collisions.erase(colPair); // remove collision pair
			}

			/*
			std::map<CollisionPair, CollisionInfo>::iterator it = collisions.find(colPair);
			if (collisions.end() != it)
			{
				collisions.erase(colPair); // remove collision pair
			}
			else
			{

			}
			*/
		}
	}
}

void ThomasTankPhysics::ResolveCollisions()
{
	for (std::map<CollisionPair, CollisionInfo>::iterator it = collisions.begin(); it != collisions.end(); ++it)
	{
		float minBounce = std::min(it->first.rigidBodyA.m_bounciness, it->first.rigidBodyB.m_bounciness);
		float velAlongNormal = Vector2::Dot(it->first.rigidBodyB.m_currentVelocity - it->first.rigidBodyA.m_currentVelocity, it->second.collisionNormal);

		if (velAlongNormal > 0)
		{
			continue;
		}
			
		float j = -(1 + minBounce) * velAlongNormal;
		float invMassA, invMassB;

		if (it->first.rigidBodyA.m_mass == 0.0f)
		{
			invMassA = 0.0f;
		}
		else
		{
			invMassA = 1 / it->first.rigidBodyA.m_mass;
		}

		if (it->first.rigidBodyB.m_mass == 0.0f)
		{
			invMassB = 0.0f;
		}
		else
		{
			invMassB = 1 / it->first.rigidBodyB.m_mass;
		}

		if (abs(it->second.penetration) > 0.01f)
		{
			PositionalCorrection(it->first);
		}
	}
}

void ThomasTankPhysics::PositionalCorrection(CollisionPair c)
{
	const float percent = 0.2f;

	float invMassA, invMassB;

	if (c.rigidBodyA.m_mass == 0.0f)
	{
		invMassA = 0.0f;
	}
	else
	{
		invMassA = 1 / c.rigidBodyA.m_mass;
	}

	if (c.rigidBodyB.m_mass == 0.0f)
	{
		invMassB = 0.0f;
	}
	else
	{
		invMassB = 1 / c.rigidBodyB.m_mass;
	}

	if (abs(collisions.find(c)->second.penetration) > 0.01f)
	{
		PositionalCorrection(collisions.find(c)->first);
	}
}

