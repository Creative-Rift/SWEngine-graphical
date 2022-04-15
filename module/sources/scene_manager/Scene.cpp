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

#include "scenes_manager/Scene.hpp"

sw::Scene::Scene(const std::string &sceneName) :
sw::AScene(sceneName)
{}

void sw::Scene::onLoad()
{
    eventManager().drop("Start");
}

void sw::Scene::onUpdate()
{
    eventManager().drop("Update");
}

void sw::Scene::onUnload()
{
    eventManager().drop("End");
}