#include "RigidBodyComponent.h"
#include "ThomasTankPhysics.h"

#include <iostream>

void RigidBodyComponent::Start()
{
	//std::cout << "RB START" << std::endl;
	m_gravity = Vector2(0.0f, 9.8f);
	//std::cout << "Gravity: (" << m_gravity.x << ", " << m_gravity.y << ")" << std::endl;
	SetAABB();
	ThomasTankPhysics::AddRigidBody(this);
}

void RigidBodyComponent::AddForce(Vector2 force)
{
	//std::cout << "Add Force: (" << force.x << ", " << force.y << ")" << std::endl;
	m_totalForces = force + m_totalForces;
	//std::cout << "Total Force: (" << m_totalForces.x << ", " << m_totalForces.y << ")" << std::endl;
}

void RigidBodyComponent::Stop()
{
	m_currentVelocity = Vector2(0.0f, 0.0f);
	m_totalForces = Vector2(0.0f, 0.0f);
}

void RigidBodyComponent::SetAABB()
{
	m_AABB.bLeft = Vector2(m_ownerTransform->m_Position.x - m_ownerRenderer->m_bounds.extents.x,
		m_ownerTransform->m_Position.y + m_ownerRenderer->m_bounds.extents.y);
	m_AABB.tRight = Vector2(m_ownerTransform->m_Position.x + m_ownerRenderer->m_bounds.extents.x,
		m_ownerTransform->m_Position.y - m_ownerRenderer->m_bounds.extents.y);

	//std::cout << "bLeft: (" << m_AABB.bLeft.x << ", " << m_AABB.bLeft.y << ")" << std::endl;
	//std::cout << "tRight: (" << m_AABB.tRight.x << ", " << m_AABB.tRight.y << ")" << std::endl;
}

void RigidBodyComponent::Integrate(float dt)
{
	//std::cout << "Integrate" << std::endl;
	if (!IsGrounded())
	{
		//std::cout << "add gravity" << std::endl;
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

	m_currentVelocity = m_currentVelocity + (acceleration * dt);
	//std::cout << "Velocity: (" << m_currentVelocity.x << ", " << m_currentVelocity.y << ")" << std::endl;

	Vector2 temp = m_ownerTransform->m_Position;
	//std::cout << "Temp Pos: (" << temp.x << ", " << temp.y << ")" << std::endl;
	//std::cout << "New Owner Pos: (" << m_ownerTransform->m_Position.x << ", " << m_ownerTransform->m_Position.y << ")" << std::endl;

	temp = temp + (m_currentVelocity * dt);
	m_ownerTransform->m_Position = temp;
	//std::cout << "New Temp Pos: (" << temp.x << ", " << temp.y << ")" << std::endl;
	//std::cout << "New Owner Pos: (" << m_ownerTransform->m_Position.x << ", " << m_ownerTransform->m_Position.y << ")" << std::endl;
	SetAABB();

	m_totalForces = Vector2(0.0f, 0.0f);
}

bool RigidBodyComponent::IsGrounded()
{
	m_isGrounded = ThomasTankPhysics::IsGrounded(this);
	return m_isGrounded;
}
