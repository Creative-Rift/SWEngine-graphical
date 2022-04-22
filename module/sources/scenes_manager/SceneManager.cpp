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
m_nameActiveScene(),
m_nameNextActiveScene()
{}

void sw::SceneManager::checkForNewScene()
{
    if (m_nameNextActiveScene.empty())
        return;
    getActiveScene().unload();
    m_nameActiveScene = m_nameNextActiveScene;
    m_nameNextActiveScene.clear();
    m_scenes.at(m_nameActiveScene).load();
}

void sw::SceneManager::createScene(std::string name)
{
    m_scenes.try_emplace(name, name);
}

void sw::SceneManager::loadScene(std::string sceneName)
{
    if (m_nameActiveScene.empty()) {
        m_nameActiveScene = sceneName;
        m_scenes.at(sceneName).load();
    } else {
        m_nameNextActiveScene = sceneName;
    }
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