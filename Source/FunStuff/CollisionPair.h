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
		return (rigidBodyA.m_Id == cp.rigidBodyA.m_Id && rigidBodyB.m_Id == cp.rigidBodyB.m_Id);
	}
	bool operator<(const CollisionPair& cp) const
	{
		return (rigidBodyA.m_Id < cp.rigidBodyA.m_Id || rigidBodyB.m_Id < cp.rigidBodyB.m_Id);
	}
	bool operator!=(const CollisionPair& cp) const { return !operator==(cp); }
	bool operator> (const CollisionPair& cp) const { return  operator< (cp); }
	bool operator<=(const CollisionPair& cp) const { return !operator> (cp); }
	bool operator>=(const CollisionPair& cp) const { return !operator< (cp); }
};