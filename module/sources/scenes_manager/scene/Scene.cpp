/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * Scene.cpp
 *
 * Description:
 */

#include "scenes_manager/scene/Scene.hpp"
#include "SceneLoadEvent.hpp"
#include "OpenGLModule.hpp"
#include "yaml-cpp/yaml.h"

sw::Scene::Scene(const std::string &sceneName) :
m_isLoad{false},
name{sceneName},
m_managersToDelete{},
m_entitiesToDelete{},
eventManager{},
resources{},
m_managers{},
m_entities{},
m_managersLayers{}
{
    m_managersLayers.needSort = true;
    eventManager.create("Start");
    eventManager.create("Update");
    eventManager.create("Unload");
}

void sw::Scene::load()
{
    if (m_isLoad) {
        sw::Speech::Warning(sw::Log::warning350(FUNCTION, name));
        return;
    }
    sw::Speech::Info(sw::Log::info350(FUNCTION, name));
    resources.loadResources();
    sw::SceneLoadEvent newScene(*this);
    sw::EventInfo info(newScene);
    sw::OpenGLModule::m_eventManager.drop("SceneLoad", info);
    m_managersLayers.sort();
    for (auto& [_, managerName] : m_managersLayers)
        m_managers[managerName]->load();
    m_isLoad = true;

    sw::Speech::Info(sw::Log::info350_Success(FUNCTION, name));
}

void sw::Scene::update()
{
    eventManager.drop("Update");
    if (!m_isLoad) {
        sw::Speech::Warning(sw::Log::warning360(FUNCTION, name));
        return;
    }

    if (m_managersLayers.needSort)
        m_managersLayers.sort();
    for (auto& [_, managerName] : m_managersLayers) {
        try {
            m_managers[managerName]->update();
        }
        catch (sw::Error& error) {
            sw::Speech::Error(error.getMessage(), error.getCode());
        }
    }

    deleteRequestedEntities();
    deleteRequestedManagers();
}

void sw::Scene::unload()
{
    eventManager.drop("Unload");
    if (!m_isLoad) {
        sw::Speech::Warning(sw::Log::warning370(FUNCTION, name));
        return;
    }
    sw::Speech::Info(sw::Log::info370(FUNCTION, name));

    resources.unloadResources();
    for (auto& [_, fact] : m_managers)
        fact->unload();
    m_managers.clear();
    m_entities.clear();
    m_managersLayers.clear();
    m_entitiesToDelete.clear();
    m_isLoad = false;

    sw::Speech::Info(sw::Log::info370_Success(FUNCTION, name));
}

void sw::Scene::save() const
{
    YAML::Node node;

    node["name"] = name;

    for (auto& [_, entity] : m_entities)
        node["entities"].push_back(entity->save());
    for (auto& [_, manager] : m_managers)
        node["manager"].push_back(manager->save());

    std::ofstream file("save/" + name + ".fish");
    file << node;
}