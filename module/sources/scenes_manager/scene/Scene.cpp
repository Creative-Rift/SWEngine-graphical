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
    eventManager.drop("Start");
}

void sw::Scene::update()
{
    eventManager.drop("Update");
}

void sw::Scene::unload()
{
    eventManager.drop("Unload");
}