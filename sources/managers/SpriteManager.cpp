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

void sw::SpriteManager::onUpdate()
{
    sw::ConcreteComponent auto& camera = m_scene.getEntity("MainCamera").getComponent<sw::Camera>("CameraManager");

    for (auto& [_, name] : m_componentsLayers) {
        auto& object = m_components[name];
        sw::ConcreteComponent auto& transform = object->entity().getComponent<sw::Transform>("TransformManager");
        glBindTexture(GL_TEXTURE_2D, object->texture()->getId());
        object->defineRect();
        object->getShader().useShader();
        object->getShader().setUniMat4("projection", camera.getProjection());
        object->getShader().setUniMat4("view", camera.getView());
        object->getShader().setUniMat4("model", transform.getMatrix());
        object->updateInvert();
        object->getVertexArray().update();
        glBindVertexArray((*object).getVertexArray().getVAO());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);
    }
}