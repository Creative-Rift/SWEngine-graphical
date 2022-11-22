/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: scale.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"
#include "GameObject.hpp"

void sw::Transform::setScale(const sw::Vector3f& value)
{
    scale(value / m_scale);
}

void sw::Transform::setScale(float x, float y, float z)
{
    scale({x / m_scale.x, y / m_scale.y, z / m_scale.z});
}

void sw::Transform::scale(const sw::Vector3f& scale)
{
    if (scale.x != 0 || scale.y != 0 || scale.z != 0) {
        m_scale *= scale;
        m_globalScale *= scale;
        for (auto& [_, entity] : m_gameObject.m_childrenMap)
            entity.get().transform().scale(scale);
        needUpdate(true);
    }
}

void sw::Transform::scale(float x, float y, float z)
{
    scale({x, y, z});
}

const sw::Vector3f& sw::Transform::getScale() const noexcept
{
    return (m_scale);
}

const sw::Vector3f& sw::Transform::getGlobalScale() const noexcept
{
    return (m_globalScale);
}