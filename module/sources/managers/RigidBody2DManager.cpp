/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: RigidBody2DManager.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"
#include "event/EventCollision.hpp"
#include "OpenGLModule.hpp"
#include "utils/Vector2.hpp"
#include "GameObject.hpp"

#include "managers/RigidBody2DManager.hpp"

void sw::RigidBody2DManager::onUpdate()
{
    auto gravity = 9.81f;
    auto currentTime = (float)sw::OpenGLModule::deltaTime();

    for (auto& [_, obj] : m_components) {
        if (!obj->isActive() || !obj->gameObject().isActive())
            continue;
        sw::ConcreteComponent auto& transform = obj->gameObject().transform();
        sw::Vector2f vel = {obj->getVelocity().x, obj->getVelocity().y};

        vel.x = obj->getVelocity().x * 100;
        vel.y += gravity / obj->getMass() * currentTime * 100;
        if (obj->m_collideX == sw::CollisionEvent::LEFT && vel.x < 0)
            vel.x = 0;
        if (obj->m_collideX == sw::CollisionEvent::RIGHT && vel.x > 0)
            vel.x = 0;

        if (obj->m_collideY == sw::CollisionEvent::DOWN && vel.y > 0)
            vel.y = 0;
        if (obj->m_collideY == sw::CollisionEvent::UP && vel.y < 0)
            vel.y = 0;
        obj->setVelocity(vel);
        transform.move(vel.x * currentTime, vel.y * currentTime);
        
        if (obj->gameObject().id >= 0)
        {
            auto &tmp = transform.getPosition();
            m_scene.m_tree.relocate(obj->gameObject().id, {tmp.x, tmp.y});
        }
        
        obj->m_collideY = sw::CollisionEvent::V_NONE;
        obj->m_collideX = sw::CollisionEvent::H_NONE;
        obj->m_lastTime = currentTime;
    }
}