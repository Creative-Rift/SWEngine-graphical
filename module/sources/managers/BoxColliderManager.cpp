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
#include "GameObject.hpp"

#include <iostream>
#include <vector>
void sw::BoxColliderManager::onUpdate()
{
    bool sendEvent = false;

    for (auto&[_, obj]: m_components) {
        if (!obj->isActive() || !obj->gameObject().isActive() || obj->isStatic())
            continue;
        sw::CollisionEvent info(obj->gameObject().name(), "target->entity().name()");
        /*
        for (auto&[name, target]: m_static) {
            if (!target->isActive() || !target->gameObject().isActive())
                continue;
            try {

                sw::ConcreteComponent auto &objTransform = obj->gameObject().transform();
                sw::ConcreteComponent auto &targetTransform = target->gameObject().transform();

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
                    m_scene.eventManager.drop("Collision", ye);
                }
            } catch (sw::Error &e) {

            }
        }*/

        auto &pos = m_scene.m_tree.get_aabb(obj->gameObject().id);

        std::cout << "BoxColliderManager positions: " << pos.min() << " " << pos.max() << std::endl;
        std::cout << "BoxColliderManager size: " << pos.size() << std::endl;
        /*       
        sw::Vector2f vel = {obj->getVelocity().x, obj->getVelocity().w};

        vel.x = obj->getVelocity().x * 100;
        vel.y += gravity / obj->getMass() * currentTime * 100;
        */
        std::vector<int> candidates{};

        Vector2f min{pos.min().x /* + vel.x*/, pos.min().y/* + vel.y*/};
        Vector2f max{pos.max().x /* + vel.x*/, pos.max().y/* + vel.y*/};
        
        //m_scene.m_tree.query(min, max, std::back_inserter(candidates));
        m_scene.m_tree.query(obj->gameObject().id, std::back_inserter(candidates));

        if (!candidates.empty())
            sendEvent = true;
        std::cout << "BoxColliderManager first candidate: " << candidates[0] << std::endl;
        std::cout << "BoxColliderManager sendEvent: " << std::boolalpha << sendEvent << std::endl;
        if (sendEvent) {
            sendEvent = false;
            sw::EventInfo ye(info);
            m_scene.eventManager.drop("Collision", ye);
        }
    }
}

void sw::BoxColliderManager::addStatic(std::string name)
{
    auto& target = m_components[name];

    m_static.emplace(std::pair<std::string, std::shared_ptr<BoxCollider>>(name, target));
    //m_components.erase(name);
}