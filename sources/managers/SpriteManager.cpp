/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: SpriteManager.cpp
** Description: [CHANGE]
*/

#include "dependencies/glad/glad.h"

#include "managers/SpriteManager.hpp"

void sw::SpriteManager::onUpdate()
{
    for (auto& [_, object] : m_components) {
        object->getShader().useShader();
        object->defineRect();
        object->updateInvert();
        object->getVertexArray().update();
        glBindVertexArray((*object).getVertexArray().getVAO());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }
}