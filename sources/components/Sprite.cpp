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
//m_texture(**sfml::Module::getTexture(std::string("MissingTexture"))),
m_textureName("MissingTexture"),
m_color(),
m_rect(),
m_invertedX(false),
m_invertedY(false)
{
    //m_rect = {0.0f, 0.0f, (float)m_texture.getSize().x, (float)m_texture.getSize().y};
    //m_vertexArray = sf::VertexArray(sf::TriangleStrip, 4);
    //m_vertexArray[0].position = {m_rect.left, m_rect.top};
    //m_vertexArray[1].position = {m_rect.left, m_rect.height};
    //m_vertexArray[2].position = {m_rect.width, m_rect.top};
    //m_vertexArray[3].position = {m_rect.width, m_rect.height};
    //m_vertexArray[0].texCoords = {m_rect.left, m_rect.top};
    //m_vertexArray[1].texCoords = {m_rect.left, m_rect.height};
    //m_vertexArray[2].texCoords = {m_rect.width, m_rect.top};
    //m_vertexArray[3].texCoords = {m_rect.width, m_rect.height};
}

const sw::Shader &sw::Sprite::getShader() const noexcept
{
    return (m_shader);
}

const sw::VertexArray &sw::Sprite::getVertexArray() const
{
    return (m_vertexArray);
}

sw::Sprite &sw::Sprite::setTexture(std::string& name)
{
    //TODO
}

sw::Sprite &sw::Sprite::setTextureRect(sw::FloatRect &rect)
{
    m_rect = rect;
}

sw::Sprite &sw::Sprite::setColor(const sw::Color &color)
{
    m_color = color;
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
    //m_vertexArray[0].texCoords = {sp.m_rect.left, sp.m_rect.top};
    //m_vertexArray[1].texCoords = {sp.m_rect.left, sp.m_rect.top + sp.m_rect.height};
    //m_vertexArray[2].texCoords = {sp.m_rect.left + sp.m_rect.width, sp.m_rect.top};
    //m_vertexArray[3].texCoords = {sp.m_rect.left + sp.m_rect.width, sp.m_rect.top + sp.m_rect.height};
    m_vertexArray[0].position = {0, 0, 0};
    m_vertexArray[1].position = {0, m_rect.height, 0};
    m_vertexArray[2].position = {m_rect.width, 0, 0};
    m_vertexArray[3].position = {m_rect.width, m_rect.height, 0};
}