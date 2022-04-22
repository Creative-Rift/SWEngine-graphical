/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * Component.cpp
 *
 * Description:
 * Implementation of Component functions
 */

#include "components/base/Component.hpp"
#include "gameObject/GameObject.hpp"

sw::Component::Component(GameObject& gameObjectRef)
        :   m_isActive{true},
            m_gameObject{gameObjectRef}
{}

std::string sw::Component::name() const
{
    return (m_gameObject.name());
}

void sw::Component::setActive(bool value)
{
    m_isActive = value;
}

bool sw::Component::isActive() const
{
    return (m_isActive);
}

sw::GameObject& sw::Component::gameObject() const
{
    return (m_gameObject);
}