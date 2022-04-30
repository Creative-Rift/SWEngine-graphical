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

YAML::Node sw::Transform::save() const
{
    YAML::Node node;

    node["entity_name"] = name();
    node["position"].push_back(m_position.x);
    node["position"].push_back(m_position.y);
    node["position"].push_back(m_position.z);
    node["scale"].push_back(m_scale.x);
    node["scale"].push_back(m_scale.y);
    node["scale"].push_back(m_scale.z);
    node["angle"] = m_angle;
    node["rotation_axis"].push_back(m_rotationAxis.x);
    node["rotation_axis"].push_back(m_rotationAxis.y);
    node["rotation_axis"].push_back(m_rotationAxis.z);

    return (node);
}