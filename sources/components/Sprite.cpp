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
//m_rect(),
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