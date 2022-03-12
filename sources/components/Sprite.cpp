/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Sprite.cpp
** Description: [CHANGE]
*/

#include "components/Sprite.hpp"

sw::Sprite::Sprite(sw::Entity& entityRef) :
sw::Component(entityRef),
m_vertexArray{},
m_texture(sw::OpenResources::m_ntext["MissingTexture"]),
m_textureName("MissingTexture"),
m_color(),
m_rect(),
m_invertedX(false),
m_invertedY(false)
{
    m_rect = {0.0f, 0.0f, (float)m_texture->getWidth(), (float)m_texture->getHeight()};
}

const sw::Shader &sw::Sprite::getShader() const noexcept
{
    return (m_shader);
}

sw::VertexArray &sw::Sprite::getVertexArray()
{
    return (m_vertexArray);
}

sw::Sprite &sw::Sprite::setTexture(std::string& name)
{
    m_texture = sw::OpenResources::m_ntext[name];
    m_rect = {0.0f, 0.0f, (float)m_texture->getWidth(), (float)m_texture->getHeight()};
    m_textureName = name;
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

void sw::Sprite::invertX(bool invert)
{
    m_invertedX = invert;
}

void sw::Sprite::invertY(bool invert)
{
    m_invertedY = invert;
}

bool sw::Sprite::isInvertX() const
{
    return (m_invertedX);
}

bool sw::Sprite::isInvertY() const
{
    return (m_invertedY);
}

void sw::Sprite::updateInvert()
{
    if (m_invertedX) {
        auto save1 = m_vertexArray[0].position;
        auto save2 = m_vertexArray[1].position;
        m_vertexArray[0].position = m_vertexArray[2].position;
        m_vertexArray[1].position = m_vertexArray[3].position;
        m_vertexArray[2].position = save1;
        m_vertexArray[3].position = save2;
    }
    if (m_invertedY) {
        auto save1 = m_vertexArray[0].position;
        auto save2 = m_vertexArray[2].position;
        m_vertexArray[0].position = m_vertexArray[1].position;
        m_vertexArray[2].position = m_vertexArray[3].position;
        m_vertexArray[1].position = save1;
        m_vertexArray[3].position = save2;
    }
}

void sw::Sprite::defineRect()
{
    float a = m_rect.left / static_cast<float>(m_texture->getWidth());
    float b = m_rect.width / static_cast<float>(m_texture->getWidth());
    float c = m_rect.top / static_cast<float>(m_texture->getHeight());
    float d = m_rect.height / static_cast<float>(m_texture->getHeight());

    m_vertexArray[1].textureCoord = {a + b, c + d};
    m_vertexArray[0].textureCoord = {a + b, c};
    m_vertexArray[3].textureCoord = {a, c};
    m_vertexArray[2].textureCoord = {a, c + d};
    m_vertexArray[1].position = {(m_rect.width), 0, 0};
    m_vertexArray[2].position = {0, 0, 0};
    m_vertexArray[3].position = {0, (m_rect.height), 0};
    m_vertexArray[0].position = {(m_rect.width), (m_rect.height), 0};
}

std::shared_ptr<sw::Texture> sw::Sprite::texture() const
{
    return (m_texture);
}