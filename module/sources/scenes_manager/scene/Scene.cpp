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
#include "Window.hpp"
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
m_configFile{"None"},
m_gameObjectId(0)
{
    m_managersLayers.needSort = true;
    eventManager.create("Awake");
    eventManager.create("Start");
    eventManager.create("Update");
    eventManager.create("Unload");
    eventManager.create("GODestroy");
}

void sw::Scene::load(bool async)
{
    if (m_isLoad) {
        sw::Speech::Warning(sw::Log::warning350(FUNCTION, name));
        return;
    }
    sw::Speech::Info(sw::Log::info350(FUNCTION, name));
    resources.loadResources();
    if (!async)
        resources.compileResources();

    sw::SceneLoadEvent newScene(*this);
    sw::EventInfo info(newScene);
    sw::Speech::flush();

    createManager<sw::AnimatorManager>("AnimatorManager");
    createManager<sw::AudioSourceManager>("AudioManager");
    createManager<sw::BoxColliderManager>("BoxColliderManager");
    m_cameraManager = createManager<sw::CameraManager>("CameraManager");
    createManager<sw::RigidBody2DManager>("RigidBody2DManager");
    createManager<sw::ScriptManager>("ScriptManager");
    createManager<sw::SpriteManager>("SpriteManager");
    createManager<sw::TextManager>("TextManager");
    createManager<sw::MeshRendererManager>("MeshRendererManager");
    createManager<sw::ModelAnimatorManager>("ModelAnimatorManager");
    createManager<sw::LightManager>("LightManager");
    createManager<sw::PrimitiveManager>("PrimitiveManager");
    createManager<sw::ButtonManager>("ButtonManager");
    sw::Speech::flush();

    if (m_configFile != "None")
        loadConfigFile();
    sw::OpenGLModule::m_eventManager.drop("SceneLoad", info);
    sw::Speech::flush();

    m_managersLayers.sort();
    for (auto& [_, managerName] : m_managersLayers)
        m_managers[managerName]->load();
    sw::Speech::flush();
    m_isLoad = true;
    eventManager.drop("Start");
    sw::Speech::Info(sw::Log::info350_Success(FUNCTION, name));
    eventManager.drop("Awake");
    //save();
    sw::Speech::flush();

}

void sw::Scene::update()
{
    if (!m_isLoad) {
        sw::Speech::Warning(sw::Log::warning360(FUNCTION, name));
        return;
    }

    if (m_managersLayers.needSort)
        m_managersLayers.sort();
    updatePhysics();
    updateLogic();

    for (auto& [_, cameraName] : m_cameraManager.value().m_componentsLayers) {
        sw::Camera& camera = *m_cameraManager.value().m_components[cameraName];
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        updateGraphics();
    }

    deleteRequestedEntities();
    deleteRequestedManagers();
}

void sw::Scene::updatePhysics()
{
    try {
        m_managers["BoxColliderManager"]->update();
        m_managers["RigidBody2DManager"]->update();
    }
    catch (sw::Error& error) {
        sw::Speech::Error(error.getMessage(), error.getCode());
    }
}

void sw::Scene::updateLogic()
{
    try {
        m_managers["AnimatorManager"]->update();
        m_managers["ModelAnimatorManager"]->update();
        m_managers["ScriptManager"]->update();
        m_managers["ButtonManager"]->update();
        eventManager.drop("Update");
        m_managers["AudioManager"]->update();
    }
    catch (sw::Error& error) {
        sw::Speech::Error(error.getMessage(), error.getCode());
    }
}

void sw::Scene::updateGraphics()
{
    try {
        m_managers["MeshRendererManager"]->update();
        m_managers["SpriteManager"]->update();
        m_managers["TextManager"]->update();
        m_managers["PrimitiveManager"]->update();
    }
    catch (sw::Error& error) {
        sw::Speech::Error(error.getMessage(), error.getCode());
    }
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
    m_managersToDelete.clear();
    eventManager.clearEvents();
    m_gameObjectId = 0;
    m_isLoad = false;
    m_tree.clear();
    m_lut.clear();

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