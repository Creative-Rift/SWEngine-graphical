/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * sceneFunction.cpp
 *
 * Description:
 * Engine Scene functions implementation
 */

#include "Engine.hpp"

void sw::Engine::deleteRequestedScenes()
{
    for (auto sceneName : m_scenesToDelete) {
        m_scenes[sceneName]->unload();
        m_scenes.erase(sceneName);
        if (m_activeScene == sceneName)
            m_activeScene.clear();
    }
    m_scenesToDelete.clear();
}

void sw::Engine::setRequestedActiveScene()
{
    if (!m_activeScene.empty())
        m_scenes[m_activeScene]->unload();
    m_activeScene = m_nextActiveScene;
    m_nextActiveScene.clear();
    m_scenes[m_activeScene]->load();
}

sw::AScene& sw::Engine::getScene(const std::string& sceneName)
try
{
    return (*m_scenes.at(sceneName));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error113(FUNCTION, sceneName));
}

sw::AScene& sw::Engine::activeScene()
try
{
    return (*m_scenes.at(m_activeScene));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error113(FUNCTION, m_activeScene));
}

void sw::Engine::deleteScene(const std::string& sceneName)
{
    if (!hasScene(sceneName)) {
        sw::Speech::Warning(sw::Log::warning133(FUNCTION, sceneName));
        return;
    }
    m_scenesToDelete.emplace(sceneName);
}

void sw::Engine::eraseScenes()
{
    for (auto& [name, _] : m_scenes)
        deleteScene(name);
}

void sw::Engine::setActiveScene(const std::string& sceneName)
{
    if (!hasScene(sceneName)) {
        sw::Speech::Warning(sw::Log::warning113(FUNCTION, sceneName));
        return;
    }
    m_nextActiveScene = sceneName;
}