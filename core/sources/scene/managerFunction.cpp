/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * managerFunction.cpp
 *
 * Description:
 * Scene Managers functions implementation
 */

#include "AScene.hpp"
#include "AManager.hpp"

sw::_IManager& sw::AScene::getManager(const std::string& managerName)
try
{
    return (*m_managers.at(managerName));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error314(FUNCTION, m_name, managerName));
}

void sw::AScene::deleteManager(const std::string& managerName)
{
    if (!hasManager(managerName)) {
        sw::Speech::Warning(sw::Log::warning334(FUNCTION, m_name, managerName));
        return;
    }
    m_managersToDelete.emplace(managerName);
}

void sw::AScene::deleteRequestedManagers()
{
    for (auto& managerName : m_managersToDelete) {
        m_managers.erase(managerName);
        for (auto& [layer, name] : m_managersLayers)
            if (name == managerName) {
                m_managersLayers.remove(std::pair<int, std::string>(layer, name));
                break;
            }
    }
    m_managersToDelete.clear();
}

void sw::AScene::setLayer(const std::string& managerName, int newLayer)
{
    if (m_managers.find(managerName) == m_managers.end()) {
        sw::Speech::Warning(sw::Log::warning314(FUNCTION, m_name, managerName));
        return;
    }
    for (auto& [layer, name] : m_managersLayers)
        if (name == managerName)
            layer = newLayer;
    m_managersLayers.needSort = true;
}

int sw::AScene::getLayer(std::string managerName) const
{
    for (auto pair : m_managersLayers)
        if (pair.second == managerName) {
            return (pair.first);
        }
    throw sw::Error(sw::Log::error314(FUNCTION, m_name, managerName));
}

void sw::AScene::eraseManagers()
{
    for (auto& [name, _] : m_managers)
        deleteManager(name);
}