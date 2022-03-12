/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Shader.cpp
** Description: [CHANGE]
*/

#include <iostream>

#include "SW/Errors.hpp"

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

void sw::Shader::useShader() const
{
    glUseProgram(getId());
}

int sw::Shader::getUniLocation(std::string &name) const
{
    int result = glGetUniformLocation(m_id, name.c_str());

    if (result == -1)
        throw sw::Error("Uniform shader variable not found", "");
    return (result);
}

void sw::Shader::setUniBool(std::string varName, bool &value) const
{
    glUniform1i(getUniLocation(varName), value);
}

void sw::Shader::setUniInt(std::string varName, int &value) const
{
    glUniform1i(getUniLocation(varName), value);
}

void sw::Shader::setUniFloat(std::string varName, float &value) const
{
    glUniform1f(getUniLocation(varName), value);
}

void sw::Shader::setUniMat4(std::string varName, const glm::mat4 &matrix) const
{
    glUniformMatrix4fv(getUniLocation(varName), 1, GL_FALSE, glm::value_ptr(matrix));
}