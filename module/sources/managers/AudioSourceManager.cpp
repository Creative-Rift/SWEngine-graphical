/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AudioSourceManager.cpp
** Description: [CHANGE]
*/

#include "managers/AudioSourceManager.hpp"

void sw::AudioSourceManager::onLoad(YAML::Node& node)
{
    for (auto component : node["components"]) {
        sw::AudioSource& audio = createComponent(component["entity_name"].as<std::string>());
        //audio.setAudio(component["audioFile"].as<std::string>());
        audio.setVolume(component["volume"].as<float>());
        audio.setPitch(component["pitch"].as<float>());
        audio.m_playOnStart = component["playOnStart"].as<bool>();
    }
    for (auto layer: node["layer"])
        setLayer(layer["name"].as<std::string>(), layer["index"].as<int>());
}

YAML::Node sw::AudioSourceManager::save() const
{
    YAML::Node node;

    node["name"] = name();
    node["valid"] = true;
    node["active"] = m_isActive;
    for (auto &[_, component]: m_components)
        node["components"].push_back(component->save());
    for (auto &[layer, name]: m_componentsLayers) {
        YAML::Node ye;
        ye["name"] = name;
        ye["index"] = layer;
        node["layer"].push_back(ye);
    }
    return (node);
}