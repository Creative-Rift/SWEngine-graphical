/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Transform.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"

sw::Transform::Transform(sw::GameObject& gameObject) :
sw::Component(gameObject),
m_matrix(1.0f),
m_position(0, 0, 0),
m_globalPosition(0, 0, 0),
m_scale(1, 1, 1),
m_globalScale(1, 1, 1),
m_angle(0),
m_rotationAxis(0, 1, 0),
m_globalRotationAxis(0, 0, 0),
m_needUpdate(false){}

bool sw::Transform::checkUpdate() const
{
    return (m_needUpdate);
}