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

#include "managers/Managers.hpp"
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
m_managersLayers{},
m_configFile{"None"}
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

    createManager<sw::AnimatorManager>("AnimatorManager");
    createManager<sw::AudioSourceManager>("AudioManager");
    createManager<sw::BoxColliderManager>("BoxColliderManager");
    createManager<sw::CameraManager>("CameraManager");
    createManager<sw::RigidBody2DManager>("RigidBody2DManager");
    createManager<sw::ScriptManager>("ScriptManager");
    createManager<sw::SpriteManager>("SpriteManager");
    createManager<sw::TextManager>("TextManager");

    if (m_configFile == "None")
        sw::OpenGLModule::m_eventManager.drop("SceneLoad", info);
    else
        loadConfigFile();
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

void sw::Scene::loadConfigFile()
{
    YAML::Node file = YAML::LoadFile(m_configFile);

    for (auto gameObject : file["entities"]) {
        sw::GameObject newGameObject = createGameObject(gameObject["name"].as<std::string>());
        newGameObject.load(gameObject);
    }
    for (auto [_, manager] : m_managers) {
        for (auto managers : file["manager"]) {
            if (managers["name"].as<std::string>() == manager->name())
                manager->onLoad(managers);
        }
    }
}