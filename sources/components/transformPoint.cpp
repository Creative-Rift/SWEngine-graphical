/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: transformPoint.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"

sw::Vector3f sw::Transform::getTransformPoint(const sw::Vector3f& point)
{
    if (m_needUpdate) {
        updateMatrix();
        m_needUpdate = false;
    }
    glm::vec4 resultMatrix = m_matrix * glm::vec4(point.x, point.y, point.z, 1);

    return (sw::Vector3f{resultMatrix.x, resultMatrix.y, resultMatrix.z});
}

sw::Vector3f sw::Transform::getTransformPoint(float x, float y, float z)
{
    if (m_needUpdate) {
        updateMatrix();
        m_needUpdate = false;
    }
    glm::vec4 resultMatrix = m_matrix * glm::vec4(x, y, z, 1);

    return (sw::Vector3f{resultMatrix.x, resultMatrix.y, resultMatrix.z});
}

sw::Vector3f sw::Transform::getGlobalTransformPoint(const sw::Vector3f& point)
{
    if (m_needUpdate) {
        m_globalMatrix = getGlobalMatrix();
        m_needUpdate = false;
    }
    glm::vec4 resultMatrix = m_globalMatrix * glm::vec4(point.x, point.y, point.z, 1);

    return (sw::Vector3f{resultMatrix.x, resultMatrix.y, resultMatrix.z});
}

sw::Vector3f sw::Transform::getGlobalTransformPoint(float x, float y, float z)
{
    if (m_needUpdate) {
        m_globalMatrix = getGlobalMatrix();
        m_needUpdate = false;
    }
    glm::vec4 resultMatrix = m_globalMatrix * glm::vec4(x, y, z, 1);

    return (sw::Vector3f{resultMatrix.x, resultMatrix.y, resultMatrix.z});
}