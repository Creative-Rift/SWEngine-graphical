/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Shader.cpp
** Description: [CHANGE]
*/

#include <iostream>

#include "dependencies/glad/glad.h"

#include "utils/Shader.hpp"

sw::Shader::Shader() :
m_id(glCreateProgram()),
m_fragment("resources/shaders/fragment_shader.glsl", ShaderSource::FRAGMENT),
m_vertex("resources/shaders/vertex_shader.glsl", ShaderSource::VERTEX),
m_success(),
m_info()
{
    glAttachShader(m_id, m_fragment.getId());
    glAttachShader(m_id, m_vertex.getId());
    glLinkProgram(m_id);
    glGetProgramiv(m_id, GL_LINK_STATUS, &m_success);
    if (!m_success) {
        glGetProgramInfoLog(m_id, 512, nullptr, m_info);
        std::cerr << "ERROR: shader linking: " << m_info << std::endl;
    }
}

sw::Shader::~Shader()
{
    glDeleteProgram(m_id);
}

const unsigned int &sw::Shader::getId() const noexcept
{
    return (m_id);
}