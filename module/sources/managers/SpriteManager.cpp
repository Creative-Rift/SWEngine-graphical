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

void sw::SpriteManager::onUpdate()
{
    sw::ConcreteComponent auto& camera = m_scene.getGameObject("MainCamera").getComponent<sw::Camera>("CameraManager");

    for (auto& [_, name] : m_componentsLayers) {
        auto& object = m_components[name];
        if (!object->isActive() || !object->gameObject().isActive())
            continue;
        sw::ConcreteComponent auto& transform = object->gameObject().transform();
        glBindTexture(GL_TEXTURE_2D, object->texture()->getId());
        defineRect(*object);
        object->getShader().useShader();
        object->getShader().setUniMat4("projection", camera.getProjection());
        object->getShader().setUniMat4("view", camera.getView());
        object->getShader().setUniMat4("model", transform.getGlobalMatrix());
        updateInvert(*object);
        object->m_vertexArray.update();
        glBindVertexArray(object->m_vertexArray.getVAO());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);
    }
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