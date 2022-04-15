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

sw::SceneManager::SceneManager() :
m_scenes()
{}

void sw::SceneManager::createScene(std::string name)
{
    m_scenes.try_emplace(name, name);
}

void sw::SceneManager::loadScene(std::string sceneName)
{
    m_scenes.at(sceneName).onLoad();
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