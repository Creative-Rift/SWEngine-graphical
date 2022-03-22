/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: RigidBody2D.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"
#include "components/BoxCollider.hpp"
#include "components/RigidBody2D.hpp"
#include "SW/Engine.hpp"

sw::RigidBody2D::RigidBody2D(sw::Entity &entity) :
sw::Component(entity),
m_velocity(0, 0),
m_maxVelocity(10, 10),
m_mass(1),
m_collideY(sw::CollisionEvent::V_NONE),
m_collideX(sw::CollisionEvent::H_NONE)
{
    m_entity.scene().eventManager()["Collision"].subscribe(this, &RigidBody2D::onCollision);
}

sw::RigidBody2D &sw::RigidBody2D::setMass(float mass)
{
    m_mass = mass;
    return (*this);
}

sw::RigidBody2D &sw::RigidBody2D::setMaxVelocity(Vector2f maxVelocity)
{
    m_maxVelocity = maxVelocity;
    return (*this);
}

sw::RigidBody2D &sw::RigidBody2D::setVelocity(Vector2f velocity)
{
    m_velocity = velocity;
    return (*this);
}

const float &sw::RigidBody2D::getMass() const
{
    return (m_mass);
}

const sw::Vector2f &sw::RigidBody2D::getMaxVelocity() const
{
    return (m_maxVelocity);
}

const sw::Vector2f &sw::RigidBody2D::getVelocity() const
{
    return (m_velocity);
}

void sw::RigidBody2D::onCollision(sw::EventInfo& info)
{
    sw::ConcreteEventInfo auto& eInfo = info.getInfo<sw::CollisionEvent>();

    if (m_entity.scene().getEntity(eInfo.m_target).getComponent<sw::BoxCollider>("BoxColliderManager").isTrigger())
        return;
    if (eInfo.m_obj == m_entity.name()) {
        m_collideX = eInfo.m_horizontal;
        m_collideY = eInfo.m_vertical;
    }
    if (m_collideY == sw::CollisionEvent::DOWN) {
        auto& transform = m_entity.getComponent<sw::Transform>("TransformManager");
        if (transform.getPosition().y + m_entity.getComponent<sw::BoxCollider>("BoxColliderManager").getSize().y > m_entity.scene().getEntity(eInfo.m_target).getComponent<sw::Transform>("TransformManager").getPosition().y)
            transform.move(0, (m_entity.scene().getEntity(eInfo.m_target).getComponent<sw::Transform>("TransformManager").getPosition().y - m_entity.getComponent<sw::Transform>("TransformManager").getPosition().y - m_entity.getComponent<sw::BoxCollider>("BoxColliderManager").getSize().y));
    }
}