/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: SpriteManager.cpp
** Description: [CHANGE]
*/

#include "dependencies/glm/gtc/matrix_transform.hpp"
#include "dependencies/glad/glad.h"

#include "managers/SpriteManager.hpp"

#include "components/Transform.hpp"

void sw::SpriteManager::onUpdate()
{
    glm::mat4 view          = glm::mat4(1.0f);
    glm::mat4 projection    = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0, 0, -10.0f));
    //projection = glm::perspective(glm::radians(45.0f), 1920.0f / 1080.0f, 0.1f, 1000.0f);
    //projection = glm::ortho(-1920.0f / 2, 1920.0f / 2, 1080.0f / 2, -1080.0f / 2, 0.3f, 1000.0f); // 0, 0 at center
    projection = glm::ortho(0.0f, 1920.0f, 1080.0f, 0.0f, 0.3f, 1000.0f);

    for (auto& [_, object] : m_components) {
        auto& transform = object->entity().getComponent<sw::Transform>("TransformManager");
        glBindTexture(GL_TEXTURE_2D, object->texture()->getId());
        object->defineRect();
        object->getShader().useShader();
        object->getShader().setUniMat4("projection", projection);
        object->getShader().setUniMat4("view", view);
        object->getShader().setUniMat4("model", transform.getMatrix());
        //object->updateInvert();
        object->getVertexArray().update();
        glBindVertexArray((*object).getVertexArray().getVAO());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);
    }
}