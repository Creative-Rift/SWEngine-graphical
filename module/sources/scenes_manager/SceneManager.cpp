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
#include "scenes_manager/scene/Scene.hpp"
#include "event/EventInfo.hpp"
#include "OpenGLModule.hpp"
#include "Window.hpp"

sw::SceneManager::SceneManager() noexcept :
m_scenes(),
m_nameActiveScene(),
m_nameNextActiveScene(),
m_async(false)
{}

void sw::SceneManager::checkForNewScene()
{
    if (m_nameNextActiveScene.empty())
        return;
    getActiveScene()->unload();
    m_nameActiveScene = m_nameNextActiveScene;
    m_nameNextActiveScene.clear();
    if (!m_async)
        m_scenes.at(m_nameActiveScene)->load();
    m_async = false;
}

void sw::SceneManager::createScene(std::string name)
{
    m_scenes.try_emplace(name, std::make_shared<sw::Scene>(name));
}

void sw::SceneManager::createScene(std::string name, std::string configFile)
{
    auto& scene = m_scenes.try_emplace(name, std::make_shared<sw::Scene>(name)).first->second;
    scene->m_configFile = configFile;
}

void sw::SceneManager::loadScene(std::string sceneName)
{
    if (m_nameActiveScene.empty()) {
        m_nameActiveScene = sceneName;
        m_scenes.at(sceneName)->load();
    } else {
        m_nameNextActiveScene = sceneName;
    }
}

std::shared_ptr<sw::AsyncScene> sw::SceneManager::loadSceneAsync(std::string sceneName)
{
    m_currentLoadingScene = getScene(sceneName);
    return (std::make_shared<sw::AsyncScene>(sceneName));
}

void sw::SceneManager::swapSceneFromAsync(sw::AsyncScene &operation, std::string sceneName)
{
    operation.finish();
    operation.m_scene->resources.compileResources();
    m_nameNextActiveScene = sceneName;
    m_async = true;
}

std::shared_ptr<sw::Scene> sw::SceneManager::getActiveScene()
{
    return (getScene(m_nameActiveScene));
}

std::map<std::string, std::shared_ptr<sw::Scene>> &sw::SceneManager::getScenes()
{
    return (m_scenes);
}

std::shared_ptr<sw::Scene> sw::SceneManager::getScene(int index)
{
    int i = 0;

    for (auto& [_, obj] : m_scenes) {
        if (i == index)
            return obj;
        i++;
    }
    throw std::exception();
}

std::shared_ptr<sw::Scene> sw::SceneManager::getScene(std::string sceneName)
{
    return (m_scenes.at(sceneName));
}