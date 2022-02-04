/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: translate.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"

void sw::Transform::setPosition(const sw::Vector3f& position)
{
    move(position - m_position);
}

void sw::Transform::setPosition(float x, float y, float z)
{
    move({x - m_position.x, y - m_position.y, z - m_position.z});
}

void sw::Transform::move(const sw::Vector3f& position)
{
    if (position.x != 0 || position.y != 0 || position.z != 0) {
        m_position += position;
        m_globalPosition += position;
        for (auto& [_, entity] : m_entity.m_childrenMap)
            entity.get().getComponent<sw::Transform>("TransformManager").move(position);
        needUpdate();
    }
}

void sw::Transform::move(float x, float y, float z)
{
    move({x, y, z});
}

sw::Vector3f sw::Transform::getPosition() const noexcept
{
    return (m_position);
}

const sw::Vector3f& sw::Transform::getGlobalPosition() const noexcept
{
    return (m_globalPosition);
}