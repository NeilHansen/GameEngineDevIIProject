#include "RigidBodyComponent.h"
#include "ThomasTankPhysics.h"

RigidBodyComponent::RigidBodyComponent()
{

}

RigidBodyComponent::~RigidBodyComponent()
{
}

void RigidBodyComponent::Start()
{

}

void RigidBodyComponent::Update()
{

}

void RigidBodyComponent::AddForce(Vector2 force)
{
	m_totalForces += force;
}

void RigidBodyComponent::Stop()
{
	m_currentVelocity = Vector2(0.0f, 0.0f);
	m_totalForces = Vector2(0.0f, 0.0f);
}

void RigidBodyComponent::SetAABB()
{

}

void RigidBodyComponent::Integrate(float dt)
{

}

bool RigidBodyComponent::IsGrounded()
{
	//m_isGrounded = ThomasTankPhysics::IsGrounded(*this);
	return false;
}
