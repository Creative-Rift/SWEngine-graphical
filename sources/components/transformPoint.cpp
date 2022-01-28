/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: transformPoint.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"

const sw::Vector3f sw::Transform::getTransformPoint(const sw::Vector3f& point) const
{
    if (m_need_update) {
        updateMatrix();
        //updateSfTransform();
        m_need_update = false;
    }
    sw::Matrixf resultMatrix = m_matrix * sw::Matrixf({{point.x}, {point.y}, {point.z}});
    std::vector<std::vector<float>> resultFlist = resultMatrix.getMatrix();

    return (sw::Vector3f{resultFlist[0][0], resultFlist[1][0], resultFlist[1][1]});
}

const sw::Vector3f sw::Transform::getTransformPoint(float x, float y, float z) const
{
    if (m_need_update) {
        updateMatrix();
        //updateSfTransform();
        m_need_update = false;
    }
    sw::Matrixf resultMatrix = m_matrix * sw::Matrixf({{x}, {y}, {z}});
    std::vector<std::vector<float>> resultFlist = resultMatrix.getMatrix();

    return (sw::Vector3f{resultFlist[0][0], resultFlist[1][0], resultFlist[1][1]});
}

const sw::Vector3f sw::Transform::getGlobalTransformPoint(const sw::Vector3f& point) const
{
    if (m_global_need_update) {
        m_globalMatrix = getGlobalMatrix();
        updateGlobalSfTransform();
        m_global_need_update = false;
    }
    sw::Matrixf resultMatrix = m_globalMatrix * sw::Matrixf({{point.x}, {point.y}, {1}});
    std::vector<std::vector<float>> resultFlist = resultMatrix.getMatrix();

    return (sw::Vector3f{resultFlist[0][0], resultFlist[1][0], resultFlist[1][1]});
}

const sw::Vector3f sw::Transform::getGlobalTransformPoint(float x, float y, float z) const
{
    if (m_global_need_update) {
        m_globalMatrix = getGlobalMatrix();
        updateGlobalSfTransform();
        m_global_need_update = false;
    }
    sw::Matrixf resultMatrix = m_globalMatrix * sw::Matrixf({{x}, {y}, {z}});
    std::vector<std::vector<float>> resultFlist = resultMatrix.getMatrix();

    return (sw::Vector3f{resultFlist[0][0], resultFlist[1][0], resultFlist[1][1]});
}

std::string sw::Transform::type() const
{
    return ("Transform");
}