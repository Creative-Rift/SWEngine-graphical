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
shader()
{}

sw::Material::Material(std::shared_ptr<sw::Texture>& texture) :
texture(texture),
shader()
{}

sw::Material::Material(std::string textureName) :
texture(sw::OpenResources::m_ntext[textureName]),
shader()
{}

sw::Material::Material(std::shared_ptr<sw::Texture>& texture, Shader& shader) :
texture(texture),
shader(shader)
{}