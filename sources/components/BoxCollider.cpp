/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BoxCollider.cpp
** Description: [CHANGE]
*/

#include "components/BoxCollider.hpp"
#include "managers/BoxColliderManager.hpp"

sw::BoxCollider::BoxCollider(sw::Entity &entity) :
sw::Component(entity),
m_size(100, 100)
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
    m_entity.scene().getManager<sw::BoxColliderManager>("BoxColliderManager").addStatic(m_entity.name());
    return (*this);
}

const bool &sw::BoxCollider::isStatic() const
{
    return (m_static);
}