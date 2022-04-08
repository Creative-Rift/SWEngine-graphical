/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Material.cpp
** Description: [CHANGE]
*/

#include "components/Material.hpp"

sw::Material::Material() :
m_texture(sw::OpenResources::m_ntext["MissingTexture"]),
m_shader()
{}

sw::Material::Material(std::shared_ptr<sw::Texture>& texture) :
m_texture(texture),
m_shader()
{}

sw::Material::Material(std::string textureName) :
m_texture(sw::OpenResources::m_ntext[textureName]),
m_shader()
{}

sw::Material::Material(std::shared_ptr<sw::Texture>& texture, Shader& shader) :
m_texture(texture),
m_shader(shader)
{}

sw::Material &sw::Material::setShader(sw::Shader shader)
{
    m_shader = shader;
    return (*this);
}

sw::Material &sw::Material::setTexture(std::string textureName)
{
    m_texture = sw::OpenResources::m_ntext[textureName];
    return (*this);
}