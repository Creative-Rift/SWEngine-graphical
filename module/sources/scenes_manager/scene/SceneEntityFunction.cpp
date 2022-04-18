/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * SceneEntityFunction.cpp
 *
 * Description:
 */

#include "scene/Scene.hpp"
#include "GameObject.hpp"

void sw::Scene::deleteRequestedEntities()
{
    for (auto& entityName : m_entitiesToDelete)
        m_entities.erase(entityName);
}

sw::GameObject& sw::Scene::createGameObject(const std::string& entityName)
{
    if (hasGameObject(entityName))
        sw::Speech::Warning(sw::Log::warning325(FUNCTION, name, entityName));
    return (dynamic_cast<sw::GameObject&>(*m_entities.try_emplace(entityName, std::make_shared<sw::GameObject>(entityName, *this)).first->second));
}

sw::GameObject& sw::Scene::getGameObject(const std::string& entityName)
try
{
    return (dynamic_cast<sw::GameObject&>(*m_entities.at(entityName)));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error315(FUNCTION, name, entityName));
}

bool sw::Scene::hasGameObject(const std::string& gameObjectName)
{
    return (m_entities.contains(gameObjectName));
}

void sw::Scene::deleteGameObject(const std::string& gameObjectName)
{
    if (!hasGameObject(gameObjectName)) {
        sw::Speech::Warning(sw::Log::warning335(FUNCTION, name, gameObjectName));
        return;
    }
    m_entitiesToDelete.emplace(gameObjectName);
}

void sw::Scene::eraseGameObject()
{
    for (auto& [nameGameObject, _] : m_entities)
        deleteGameObject(nameGameObject);
}

std::size_t sw::Scene::gameObjectCount() const
{
    return (m_entities.size());
}