/*
** ShipWreck Engine , 2022
** PrimitiveManager.cpp
*/

#include "PrimitiveManager.hpp"
#include "GameObject.hpp"
#include "Components.hpp"

void sw::PrimitiveManager::onLoad(YAML::Node &node)
{

}

YAML::Node sw::PrimitiveManager::save() const
{
    return {};
}

void sw::PrimitiveManager::onUpdate()
{
    sw::ConcreteComponent auto& camera = m_scene.getGameObject("MainCamera").getComponent<sw::Camera>("CameraManager");
    for (auto& [_, name] : m_componentsLayers) {
        auto& object = m_components[name];
        if (!object->isActive() || !object->gameObject().isActive())
            continue;
        sw::ConcreteComponent auto& transform = object->gameObject().transform();
        object->m_shader->useShader();
        object->m_shader->setUniMat4("projection", camera.getProjection());
        object->m_shader->setUniMat4("view", camera.getView());
        object->m_shader->setUniMat4("model", glm::mat4(1.0f));
        object->m_shader->setUniInt("hasTexture", 0);
        object->update();
        glBindVertexArray(object->m_vao);
        glDrawArrays(GL_LINE_LOOP, 0, 4);
        glBindVertexArray(0);
    }
}