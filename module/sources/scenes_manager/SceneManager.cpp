/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * SceneManager.cpp
 *
 * Description:
 */

#include "scenes_manager/SceneManager.hpp"
#include "scenes_manager/SceneLoadEvent.hpp"
#include "scenes_manager/scene/Scene.hpp"
#include "event/EventInfo.hpp"
#include "OpenGLModule.hpp"

sw::SceneManager::SceneManager() noexcept :
m_scenes(),
m_nameActiveScene()
{}

void sw::SceneManager::createScene(std::string name)
{
    m_scenes.try_emplace(name, name);
}

void sw::SceneManager::loadScene(std::string sceneName)
{
    m_scenes.at(sceneName).load();
    sw::SceneLoadEvent newScene(m_scenes.at(sceneName));
    sw::EventInfo info(newScene);
    sw::OpenGLModule::m_eventManager.drop("SceneLoad", info);
    m_nameActiveScene = sceneName;
}

sw::Scene sw::SceneManager::getActiveScene()
{
    return (getScene(m_nameActiveScene));
}

sw::Scene& sw::SceneManager::getScene(int index)
{
    int i = 0;

    for (auto& [_, obj] : m_scenes) {
        if (i == index)
            return obj;
        i++;
    }
    throw std::exception();
}

sw::Scene &sw::SceneManager::getScene(std::string sceneName)
{
    return (m_scenes.at(sceneName));
}