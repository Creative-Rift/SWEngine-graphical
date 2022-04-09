/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * entityFunction.cpp
 *
 * Description:
 * Scene Entities functions implementation
 */

#include "AScene.hpp"
#include "Entity.hpp"

void sw::AScene::deleteRequestedEntities()
{
    for (auto& name : m_entitiesToDelete)
        m_entities.erase(name);
}

sw::Entity& sw::AScene::createEntity(const std::string& entityName)
{
    if (hasEntity(entityName))
        sw::Speech::Warning(sw::Log::warning325(FUNCTION, m_name, entityName));
    return (static_cast<sw::Entity&>(*m_entities.try_emplace(entityName, std::make_unique<sw::Entity>(entityName, *this)).first->second));
}

sw::Entity& sw::AScene::getEntity(const std::string& entityName)
try
{
    return (static_cast<sw::Entity&>(*m_entities.at(entityName)));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error315(FUNCTION, m_name, entityName));
}

void sw::AScene::deleteEntity(const std::string& entityName)
{
    if (!hasEntity(entityName)) {
        sw::Speech::Warning(sw::Log::warning335(FUNCTION, m_name, entityName));
        return;
    }
    m_entitiesToDelete.emplace(entityName);
}

void sw::AScene::eraseEntities()
{
    for (auto& [name, _] : m_entities)
        deleteEntity(name);
}