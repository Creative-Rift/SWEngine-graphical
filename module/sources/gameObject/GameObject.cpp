/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * GameObject.inl
 *
 * Description:
 */

#include "gameObject/GameObject.hpp"
#include "components/Transform.hpp"

sw::GameObject::GameObject(const std::string& GameObjectName, sw::Scene& sceneRef)
        :   m_isActive(true),
            m_name(GameObjectName),
            m_scene(sceneRef),
            transform(createComponent<sw::Transform>("TransformManager"))
{}

sw::GameObject::GameObject(const std::string& gameObjectName, sw::Scene& sceneRef, bool isActive)
        :   m_isActive(isActive),
            m_name(gameObjectName),
            m_scene(sceneRef),
            transform(createComponent<sw::Transform>("TransformManager"))
{}
