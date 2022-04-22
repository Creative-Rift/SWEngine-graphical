/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BoxCollider.cpp
** Description: [CHANGE]
*/

#include "components/BoxCollider.hpp"
#include "managers/BoxColliderManager.hpp"
#include "GameObject.hpp"

sw::BoxCollider::BoxCollider(sw::GameObject& gameObject) :
sw::Component(gameObject),
m_size(100, 100),
m_static(false),
m_isTrigger(false)
{}

sw::BoxCollider &sw::BoxCollider::setSize(Vector2f size)
{
    m_size = size;
    return (*this);
}

sw::BoxCollider &sw::BoxCollider::setSize(float x, float y)
{
    m_size.x = x;
    m_size.y = y;
    return (*this);
}

const sw::Vector2f &sw::BoxCollider::getSize() const
{
    return (m_size);
}

sw::BoxCollider &sw::BoxCollider::setStatic(bool state)
{
    m_static = state;
    m_gameObject.scene().getManager<sw::BoxColliderManager>("BoxColliderManager").addStatic(m_gameObject.name());
    return (*this);
}

const bool &sw::BoxCollider::isStatic() const
{
    return (m_static);
}

sw::BoxCollider &sw::BoxCollider::setTrigger(bool trigger)
{
    m_isTrigger = trigger;
    return (*this);
}

const bool &sw::BoxCollider::isTrigger() const
{
    return (m_isTrigger);
}
