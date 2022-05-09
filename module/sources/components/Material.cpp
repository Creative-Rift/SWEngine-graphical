/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Material.cpp
** Description: [CHANGE]
*/

#include "components/Material.hpp"

sw::Material::Material() :
texture(sw::OpenResources::m_ntext["MissingTexture"]),
shader(),
m_name{"MissingTexture"}
{}

sw::Material::Material(std::shared_ptr<sw::Texture>& texture) :
texture(texture),
shader()
{}

sw::Material::Material(std::string textureName) :
texture(sw::OpenResources::m_ntext[textureName]),
shader(),
m_name{textureName}
{}

sw::Material::Material(std::shared_ptr<sw::Texture>& texture, Shader& shader) :
texture(texture),
shader(shader)
{}

sw::Material &sw::Material::setShader(sw::Shader shader)
{
    shader = shader;
    return (*this);
}

sw::Material &sw::Material::setTexture(std::string textureName)
{
    texture = sw::OpenResources::m_ntext[textureName];
    m_name = textureName;
    return (*this);
}

YAML::Node sw::Material::save() const
{
    YAML::Node node;

    node["textureName"] = m_name;
    return node;
}