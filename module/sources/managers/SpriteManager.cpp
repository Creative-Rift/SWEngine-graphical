/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: SpriteManager.cpp
** Description: [CHANGE]
*/

#include "dependencies/glad/glad.h"

#include "managers/SpriteManager.hpp"

#include "components/Transform.hpp"
#include "components/Camera.hpp"
#include "GameObject.hpp"

void sw::SpriteManager::onLoad(YAML::Node& node) {
    for (auto component: node["components"]) {
        sw::Sprite &sprite = createComponent(component["entity_name"].as<std::string>());
        sprite.m_invertedX = component["invertX"].as<bool>();
        sprite.m_invertedY = component["invertY"].as<bool>();
        sprite.m_rect.top = component["rect"][0].as<float>();
        sprite.m_rect.left = component["rect"][1].as<float>();
        sprite.m_rect.width = component["rect"][2].as<float>();
        sprite.m_rect.height = component["rect"][3].as<float>();
        sprite.m_color.load(component["color"]);
        sprite.m_material.load(component["material"]);
    }
    for (auto layer: node["layer"])
        setLayer(layer["name"].as<std::string>(), layer["index"].as<int>());
}

void sw::SpriteManager::onUpdate()
{
    sw::ConcreteComponent auto& camera = m_scene.getGameObject("MainCamera").getComponent<sw::Camera>("CameraManager");
    camera.setProjection(sw::Camera::ORTHOGRAPHIC);
    for (auto& [_, name] : m_componentsLayers) {
        auto& object = m_components[name];
        if (!object->isActive() || !object->gameObject().isActive())
            continue;
        sw::ConcreteComponent auto& transform = object->gameObject().transform();
        glBindTexture(GL_TEXTURE_2D, object->texture()->getId());
        defineRect(*object);
        object->getShader()->useShader();
        object->getShader()->setUniMat4("projection", camera.getProjection());
        object->getShader()->setUniMat4("view", camera.getView());
        object->getShader()->setUniMat4("model", transform.getGlobalMatrix());
        updateInvert(*object);
        object->m_vertexArray.update();
        glBindVertexArray(object->m_vertexArray.getVAO());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);
    }
    camera.setProjection(sw::Camera::PERSPECTIVE);
}

void sw::SpriteManager::updateInvert(sw::Sprite& sprite)
{
    if (sprite.m_invertedX) {
        auto save1 = sprite.m_vertexArray[0].position;
        auto save2 = sprite.m_vertexArray[1].position;
        sprite.m_vertexArray[0].position = sprite.m_vertexArray[3].position;
        sprite.m_vertexArray[1].position = sprite.m_vertexArray[2].position;
        sprite.m_vertexArray[2].position = save2;
        sprite.m_vertexArray[3].position = save1;
    }
    if (sprite.m_invertedY) {
        auto save1 = sprite.m_vertexArray[0].position;
        auto save2 = sprite.m_vertexArray[2].position;
        sprite.m_vertexArray[0].position = sprite.m_vertexArray[1].position;
        sprite.m_vertexArray[2].position = sprite.m_vertexArray[3].position;
        sprite.m_vertexArray[1].position = save1;
        sprite.m_vertexArray[3].position = save2;
    }
}

void sw::SpriteManager::defineRect(sw::Sprite& sprite)
{
    float a = sprite.m_rect.left / static_cast<float>(sprite.m_material.texture->getWidth());
    float b = sprite.m_rect.width / static_cast<float>(sprite.m_material.texture->getWidth());
    float c = sprite.m_rect.top / static_cast<float>(sprite.m_material.texture->getHeight());
    float d = sprite.m_rect.height / static_cast<float>(sprite.m_material.texture->getHeight());

    sprite.m_vertexArray[1].textureCoord = {a + b, c + d};
    sprite.m_vertexArray[0].textureCoord = {a + b, c};
    sprite.m_vertexArray[3].textureCoord = {a, c};
    sprite.m_vertexArray[2].textureCoord = {a, c + d};
    sprite.m_vertexArray[1].position = {(sprite.m_rect.width), 0, 0};
    sprite.m_vertexArray[2].position = {0, 0, 0};
    sprite.m_vertexArray[3].position = {0, (sprite.m_rect.height), 0};
    sprite.m_vertexArray[0].position = {(sprite.m_rect.width), (sprite.m_rect.height), 0};
}

YAML::Node sw::SpriteManager::save() const
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