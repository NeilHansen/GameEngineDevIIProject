//#include "GameObject.h"
#include "RigidBodyComponent.h"
#include "ThomasTankPhysics.h"

void RigidBodyComponent::Start()
{
	SetAABB();
	ThomasTankPhysics::AddRigidBody(*this);
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

// TODO
void RigidBodyComponent::SetAABB() // need access to renderer sprite bounds(how do we know position based off bounds?)
{
	//m_AABB.bLeft = Vector2(1,1);
	// m_AABB.bLeft = Vector2(1,1);
}

void RigidBodyComponent::Integrate(float dt)
{
	if (m_obeysGravity && !IsGrounded())
	{
		AddForce(m_gravity);
	}
	else if (abs(m_currentVelocity.y) < 0.05f)
	{
		m_currentVelocity.y = 0.0f;
	}

	Vector2 acceleration = m_totalForces / m_mass;
	if (m_mass == 0.0f)
	{
		acceleration = Vector2(0.0f, 0.0f);
	}

	m_currentVelocity += acceleration * dt;

	Vector2 temp = m_owner.m_Transform.m_Position;
	temp += m_currentVelocity * dt;
	m_owner.m_Transform.m_Position = temp;
	SetAABB();

	m_totalForces = Vector2(0.0f, 0.0f);
}

bool RigidBodyComponent::IsGrounded()
{
	m_isGrounded = ThomasTankPhysics::IsGrounded(*this);
	return m_isGrounded;
}
