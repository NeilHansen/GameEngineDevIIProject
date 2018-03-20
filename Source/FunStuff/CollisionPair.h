#pragma once
#include "RigidBodyComponent.h"

struct CollisionPair
{
public:
	CollisionPair() {}
	~CollisionPair() {}

	RigidBodyComponent rigidBodyA;
	RigidBodyComponent rigidBodyB;

	bool CollisionPair::operator==(const CollisionPair& cp) const
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