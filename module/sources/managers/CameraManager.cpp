/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: CameraManager.cpp
** Description: [CHANGE]
*/

#include "managers/CameraManager.hpp"

void sw::CameraManager::onLoad(YAML::Node& node)
{
    for (auto component : node["components"]) {
        sw::Camera& camera = createComponent(component["entity_name"].as<std::string>());
        camera.m_fov = component["fov"].as<float>();
        camera.m_size = component["size"].as<float>();
        camera.m_clippingNear = component["clipNear"].as<float>();
        camera.m_clippingFar = component["clipFar"].as<float>();
        camera.m_type = component["type"].as<int>() == 1 ? Camera::ORTHOGRAPHIC : Camera::PERSPECTIVE;
    }
}

YAML::Node sw::CameraManager::save() const
{
    YAML::Node node;

    node["valid"] = true;
    node["name"] = name();
    node["active"] = m_isActive;
    for (auto &[_, component]: m_components)
        node["components"].push_back(component->save());
    for (auto &[name, layer]: m_componentsLayers) {
        YAML::Node ye;
        ye["name"] = name;
        ye["index"] = layer;
        node["layer"].push_back(ye);
    }
    return (node);
}