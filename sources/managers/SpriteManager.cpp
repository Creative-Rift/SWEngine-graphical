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
    for (auto& [name, object] : m_components) {
        glUseProgram((*object).getShader().getId());
        glBindVertexArray((*object).getVertexArray().getVAO());
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}