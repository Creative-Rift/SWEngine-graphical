/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Entity.cpp
 *
 * Description:
 * Entity functions implementation
 */

#include "Entity.hpp"
#include "Component.hpp"

void sw::Entity::addChild(const std::string& entityName)
{
    auto& entity = m_scene.getEntity(entityName);

    entity.m_parent = *this;
    m_childrenMap.insert({entity.m_name, entity});
}

void sw::Entity::removeChild(const std::string& entityName)
{
    auto& entity = m_scene.getEntity(entityName);

    entity.m_parent.erase();
    m_childrenMap.erase(entityName);
}

void sw::Entity::deleteComponent(const std::string& managerName)
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

void sw::Entity::setLayer(const std::string& managerName, int layer)
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