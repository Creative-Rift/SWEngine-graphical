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
            m_scene(sceneRef)
{}

sw::GameObject::GameObject(const std::string& gameObjectName, sw::Scene& sceneRef, bool isActive)
        :   m_isActive(isActive),
            m_name(gameObjectName),
            m_scene(sceneRef)
{}

std::string sw::GameObject::name() const
{
    return (m_name);
}

void sw::GameObject::deleteComponent(const std::string& managerName)
try
{
    return (m_scene.getManager(managerName).deleteComponent(m_name));
}
catch (sw::Error& error)
{
    std::string code = error.getCode();
    if (code == "4314")
        throw sw::Error(sw::Log::error514(FUNCTION, m_name, managerName));
    else
        throw error;
}

void sw::GameObject::setLayer(const std::string& managerName, int layer)
try
{
    return (m_scene.getManager(managerName).setLayer(m_name, layer));
}
catch (sw::Error& error)
{
    std::string code = error.getCode();
    if (code == "4314")
        throw sw::Error(sw::Log::error514(FUNCTION, m_name, managerName));
    else
        throw error;
}