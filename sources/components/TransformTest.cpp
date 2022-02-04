/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Transform.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"

sw::Transform::Transform(sw::Entity& entityRef) :
sw::Component(entityRef),
m_matrix(1.0f),
m_position(0, 0, 0),
m_globalPosition(0, 0, 0),
m_scale(1, 1, 1),
m_globalScale(1, 1, 1),
m_angle(0),
m_rotation(0, 1, 0),
m_globalRotation(0, 0, 0),
m_need_update(false){}

bool sw::Transform::checkUpdate() const
{
    return (m_need_update);
}

std::string sw::Transform::type() const
{
    return ("Transform");
}