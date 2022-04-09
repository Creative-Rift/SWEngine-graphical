/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BoxColliderManager.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"

#include "managers/BoxColliderManager.hpp"
#include "event/EventCollision.hpp"

void sw::BoxColliderManager::onUpdate()
{
    bool sendEvent = false;

    for (auto&[_, obj]: m_components) {
        sw::CollisionEvent info(obj->entity().name(), "target->entity().name()");
        if (!obj->isActive() || !obj->entity().isActive() || obj->isStatic())
            continue;
        for (auto&[name, target]: m_static) {
            if (!target->isActive() || !target->entity().isActive())
                continue;
            try {

                sw::ConcreteComponent auto &objTransform = obj->entity().getComponent<sw::Transform>(
                        "TransformManager");
                sw::ConcreteComponent auto &targetTransform = target->entity().getComponent<sw::Transform>(
                        "TransformManager");

                bool collisionX = objTransform.getPosition().x + obj->getSize().x >= targetTransform.getPosition().x &&
                                  targetTransform.getPosition().x + target->getSize().x >= objTransform.getPosition().x;
                bool collisionY = objTransform.getPosition().y + obj->getSize().y >= targetTransform.getPosition().y &&
                                  targetTransform.getPosition().y + target->getSize().y >= objTransform.getPosition().y;

                if (collisionX && collisionY) {
                    if (info.m_horizontal == sw::CollisionEvent::H_NONE) {
                        info.m_horizontal = (targetTransform.getPosition().x >
                                             objTransform.getPosition().x + obj->getSize().x / 2)
                                            ? CollisionEvent::RIGHT : CollisionEvent::LEFT;
                        info.m_horizontal = (targetTransform.getPosition().y < objTransform.getPosition().y + 1 ||
                                             targetTransform.getPosition().y >
                                             objTransform.getPosition().y + obj->getSize().y - 1
                                             ? CollisionEvent::H_NONE : info.m_horizontal);
                    }
                    if (info.m_vertical == sw::CollisionEvent::V_NONE) {
                        info.m_target = name;
                        info.m_vertical = (targetTransform.getPosition().y >
                                           objTransform.getPosition().y + obj->getSize().y / 2) ? CollisionEvent::DOWN
                                                                                                : CollisionEvent::UP;
                        info.m_vertical = (targetTransform.getPosition().x < objTransform.getPosition().x + 1 ||
                                           targetTransform.getPosition().x >
                                           objTransform.getPosition().x + obj->getSize().x - 1 ? CollisionEvent::V_NONE
                                                                                               : info.m_vertical);

                    }
                    sendEvent = true;
                }
                if (sendEvent) {
                    sendEvent = false;
                    sw::EventInfo ye(info);
                    m_scene.eventManager().drop("Collision", ye);
                }
            } catch (sw::Error &e) {

            }
        }
    }
}

void sw::BoxColliderManager::addStatic(std::string name)
{
    auto& target = m_components[name];

    m_static.emplace(std::pair<std::string, std::shared_ptr<BoxCollider>>(name, target));
    //m_components.erase(name);
}