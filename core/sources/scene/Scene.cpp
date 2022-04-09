/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Scene.cpp
 *
 * Description:
 * Scene functions implementation
 */

// @TODO check if Resources list is not empty

#include "AScene.hpp"
#include "Entity.hpp"
#include "Engine.hpp"
#include "Speech.hpp"

sw::AScene::AScene(const std::string& sceneName)
    :   m_isLoad{false},
        m_name{sceneName},
        m_managersToDelete{},
        m_entitiesToDelete{},
        m_eventManager{},
        m_resources{sw::Engine::getModule().createResourceInstance()},
        m_managers{},
        m_entities{},
        m_managersLayers{}
{
    m_managersLayers.needSort = true;
}

void sw::AScene::load()
try
{
    if (m_isLoad) {
        sw::Speech::Warning(sw::Log::warning350(FUNCTION, m_name));
        return;
    }
    sw::Speech::Info(sw::Log::info350(FUNCTION, m_name));
    
    eventManager().create("Start");
    eventManager().create("Update");
    eventManager().create("End");
    m_resources->loadResources();
    onLoad();
    m_managersLayers.sort();
    for (auto& [_, managerName] : m_managersLayers)
        m_managers[managerName]->load();
    m_isLoad = true;

    sw::Speech::Info(sw::Log::info350_Success(FUNCTION, m_name));
}
catch (sw::Error& error) {
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error(sw::Log::error350(FUNCTION, m_name));
}

void sw::AScene::update()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning(sw::Log::warning360(FUNCTION, m_name));
        return;
    }
    sw::Speech::Info(sw::Log::info360(FUNCTION, m_name));

    if (m_managersLayers.needSort)
        m_managersLayers.sort();
    onUpdate();
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

    sw::Speech::Info(sw::Log::info360_Success(FUNCTION, m_name));
}
catch (sw::Error& error) {
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error(sw::Log::error360(FUNCTION, m_name));
}

void sw::AScene::unload()
try
{
    if (!m_isLoad) {
        sw::Speech::Warning(sw::Log::warning370(FUNCTION, m_name));
        return;
    }
    sw::Speech::Info(sw::Log::info370(FUNCTION, m_name));

    onUnload();
    m_resources->unloadResources();
    for (auto& [_, fact] : m_managers)
        fact->unload();
    m_managers.clear();
    m_entities.clear();
    m_managersLayers.clear();
    m_entitiesToDelete.clear();
    m_isLoad = false;

    sw::Speech::Info(sw::Log::info370_Success(FUNCTION, m_name));
}
catch (sw::Error& error) {
    sw::Speech::Error(error.getMessage(), error.getCode());
    throw sw::Error(sw::Log::error370(FUNCTION, m_name));
}

sw::AResources& sw::AScene::resources()
{
    if (m_resources == nullptr)
        throw sw::Error(std::string(FUNCTION) + " - Resource of Scene <" + m_name + "> has not be created.", "4317");
    return (*m_resources);
}