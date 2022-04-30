/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Sprite.cpp
** Description: [CHANGE]
*/


#include "components/Sprite.hpp"

sw::Sprite::Sprite(sw::GameObject& gameObject) :
sw::Component(gameObject),
m_vertexArray{},
m_material(),
m_color(),
m_rect(),
m_invertedX(false),
m_invertedY(false)
{
    m_rect = {0.0f, 0.0f, (float)m_material.texture->getWidth(), (float)m_material.texture->getHeight()};
}

const sw::Shader &sw::Sprite::getShader() const noexcept
{
    return (m_material.shader);
}

sw::Material &sw::Sprite::getMaterial() noexcept
{
    return (m_material);
}

sw::Sprite &sw::Sprite::setTexture(std::string& name)
{
    m_material.texture = sw::OpenResources::m_ntext[name];
    m_rect = {0.0f, 0.0f, (float)m_material.texture->getWidth(), (float)m_material.texture->getHeight()};
    return (*this);
}

sw::Sprite &sw::Sprite::setTextureRect(sw::FloatRect &rect)
{
    m_rect = rect;
    return (*this);
}

sw::Sprite &sw::Sprite::setColor(const sw::Color &color)
{
    m_color = color;
    m_vertexArray[1].color = m_color;
    m_vertexArray[0].color = m_color;
    m_vertexArray[3].color = m_color;
    m_vertexArray[2].color = m_color;
    return (*this);
}

sw::Sprite& sw::Sprite::flipOnX(bool invert)
{
    m_invertedX = invert;
    return (*this);
}

sw::Sprite& sw::Sprite::flipOnY(bool invert)
{
    m_invertedY = invert;
    return (*this);
}

bool sw::Sprite::isFlippedX() const
{
    return (m_invertedX);
}

bool sw::Sprite::isFlippedY() const
{
    return (m_invertedY);
}

std::shared_ptr<sw::Texture> sw::Sprite::texture() const
{
    return (m_material.texture);
}

YAML::Node sw::Sprite::save() const
{
    YAML::Node node;

    node["entity_name"] = name();
    node["invertX"] = isFlippedX();
    node["invertY"] = isFlippedY();
    node["rect"].push_back(m_rect.top);
    node["rect"].push_back(m_rect.left);
    node["rect"].push_back(m_rect.width);
    node["rect"].push_back(m_rect.height);
    node["color"].push_back(m_color.r);
    node["color"].push_back(m_color.g);
    node["color"].push_back(m_color.b);
    node["color"].push_back(m_color.a);

    return (node);
}