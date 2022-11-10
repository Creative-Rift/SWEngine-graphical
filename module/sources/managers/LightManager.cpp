/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: LightManager.cpp
** Description: [CHANGE]
*/

#include "OpenGLModule.hpp"

#include "GameObject.hpp"
#include "LightManager.hpp"

void sw::LightManager::onUpdate()
{}

YAML::Node sw::LightManager::save() const
{
    YAML::Node node;

    //node["name"] = name();
    //node["valid"] = true;
    //node["active"] = m_isActive;
    //for (auto &[_, component]: m_components)
    //    node["components"].push_back(component->save());
    //for (auto &[layer, name]: m_componentsLayers) {
    //    YAML::Node ye;
    //    ye["name"] = name;
    //    ye["index"] = layer;
    //    node["layer"].push_back(ye);
    //}
    return (node);
}

void sw::LightManager::onLoad(YAML::Node& node)
{
    for (auto component : node["components"]) {
    }
    for (auto layer: node["layer"])
        setLayer(layer["name"].as<std::string>(), layer["index"].as<int>());
}