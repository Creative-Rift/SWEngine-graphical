/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Matrix.cpp
** Description: [CHANGE]
*/

#include "dependencies/glm/gtc/matrix_transform.hpp"

#include "components/Transform.hpp"

void sw::Transform::updateMatrix() noexcept
{
    m_matrix = glm::mat4(1.0f);
    m_matrix = glm::translate(m_matrix, glm::vec3(m_position.x, m_position.y, m_position.z));
    m_matrix = glm::rotate(m_matrix, glm::radians(m_angle), glm::vec3(m_rotation.x, m_rotation.y, m_rotation.z));
    m_matrix = glm::scale(m_matrix, glm::vec3(m_scale.x, m_scale.y, m_scale.z));
}

const glm::mat4& sw::Transform::getMatrix() noexcept
{
    if (m_needUpdate) {
        updateMatrix();
        m_needUpdate = false;
    }
    return (m_matrix);
}

const glm::mat4& sw::Transform::getGlobalMatrix()
{
    if (m_needUpdate) {
        m_globalMatrix = getMatrix();
        if (m_entity.m_parent.hasValue())
            m_globalMatrix = m_globalMatrix * m_entity.m_parent.value().getComponent<sw::Transform>("TransformFact").getGlobalMatrix();
        m_needUpdate = false;
    }
    return (m_globalMatrix);
}