/*
** ShipWreck Engine , 2022
** Light.cpp
*/

#include "Light.hpp"

sw::Light::Light(sw::GameObject &gameObject) :
sw::Component(gameObject),
m_type(DIRECTIONAL),
m_pos(-0.2f, -1.0f, -0.3f),
m_ambient(0.4f, 0.4f, 0.4f),
m_diffuse(0.5f, 0.5f, 0.5f),
m_specular(1.0f, 1.0f, 1.0f),
m_constant(1.0f),
m_linear(0.09f),
m_quadratic(0.032f),
m_shininess(32.0f)
{}

sw::Light &sw::Light::setLightType(sw::Light::LightType type)
{
    m_type = type;
    return (*this);
}

int sw::Light::getType() const
{
    return (m_type);
}