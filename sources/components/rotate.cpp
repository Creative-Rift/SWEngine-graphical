/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: rotate.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"

void sw::Transform::setRotation(float angle, float rotationX, float rotationY, float rotationZ)
{
    if (rotationX != 0 || rotationY != 0 || rotationZ != 0 || angle != 0) {
        m_angle = angle;
        m_rotation.x = rotationX;
        m_rotation.y = rotationY;
        m_rotation.z = rotationZ;
        m_globalRotation.x = rotationX;
        m_globalRotation.y = rotationY;
        m_globalRotation.z = rotationZ;
        for (auto& [_, entity] : m_entity.m_childrenMap)
            entity.get().getComponent<sw::Transform>("TransformManager").setRotation(rotationX, rotationY, rotationZ);
        needUpdate();
    }}

void sw::Transform::rotate(float angle, float rotationX, float rotationY, float rotationZ)
{
    if (rotationX != 0 || rotationY != 0 || rotationZ != 0 || angle != 0) {
        m_angle += angle;
        m_rotation.x += rotationX;
        m_rotation.y += rotationY;
        m_rotation.z += rotationZ;
        m_globalRotation.x += rotationX;
        m_globalRotation.y += rotationY;
        m_globalRotation.z += rotationZ;
        for (auto& [_, entity] : m_entity.m_childrenMap)
            entity.get().getComponent<sw::Transform>("TransformManager").rotate(rotationX, rotationY, rotationZ);
        needUpdate();
    }
}

sw::Vector3f sw::Transform::getRotation() const
{
    return (m_rotation);
}

float sw::Transform::getAngle() const
{
    return (m_angle);
}

sw::Vector3f sw::Transform::getRadianRotation() const
{
    return (m_rotation * (3.14f / 180));
}

sw::Vector3f sw::Transform::getGlobalRotation() const
{
    return (m_globalRotation);
}

sw::Vector3f sw::Transform::getGlobalRadianRotation() const
{
    return (m_globalRotation * (3.14f / 180));
}