/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * SceneManagerFunction.hpp
 *
 * Description:
 */

#include "scenes_manager/scene/Scene.hpp"

sw::_IManager& sw::Scene::getManager(const std::string& managerName)
try
{
    return (*m_managers.at(managerName));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error314(FUNCTION, name, managerName));
}

void sw::Scene::deleteRequestedManagers()
{
    for (auto& managerName : m_managersToDelete) {
        m_managers.erase(managerName);
        for (auto& [layer, managerLayerName] : m_managersLayers)
            if (managerLayerName == managerName) {
                m_managersLayers.remove(std::pair<int, std::string>(layer, name));
                break;
            }
    }
    m_managersToDelete.clear();
}

void sw::Scene::deleteManager(const std::string& managerName)
{
    if (!hasManager(managerName)) {
        sw::Speech::Warning(sw::Log::warning334(FUNCTION, name, managerName));
        return;
    }
    m_managersToDelete.emplace(managerName);
}

void sw::Scene::eraseManagers()
{
    for (auto& [managerName, _] : m_managers)
        deleteManager(managerName);
}

std::size_t sw::Scene::managersCount() const
{
    return (m_managers.size());
}

void sw::Scene::setOrder(const std::string& managerName, int newLayer)
{
    if (m_managers.find(managerName) == m_managers.end()) {
        sw::Speech::Warning(sw::Log::warning314(FUNCTION, name, managerName));
        return;
    }
    for (auto& [layer, sceneName] : m_managersLayers)
        if (sceneName == managerName)
            layer = newLayer;
    m_managersLayers.needSort = true;
}

int sw::Scene::getOrder(std::string managerName) const
{
    for (const auto& pair : m_managersLayers)
        if (pair.second == managerName)
            return (pair.first);
    throw sw::Error(sw::Log::error314(FUNCTION, name, managerName));
}