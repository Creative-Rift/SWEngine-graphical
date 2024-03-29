/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Shader.cpp
** Description: [CHANGE]
*/

#include <iostream>

#include "../exception/Error.hpp"

#include "dependencies/glad/glad.h"

#include "utils/Shader.hpp"

sw::Shader::Shader() :
m_id(0),
m_fragment("resources/shaders/default.fs.glsl", ShaderSource::FRAGMENT),
m_vertex("resources/shaders/default.vs.glsl", ShaderSource::VERTEX),
m_fragmentPath("resources/shaders/default.fs.glsl"),
m_vertexPath("resources/shaders/default.vs.glsl"),
m_success(),
m_info(),
m_loaded(false)
{}

sw::Shader::Shader(std::string fragment, std::string vertex) :
m_id(0),
m_fragmentPath(fragment),
m_vertexPath(vertex),
m_fragment(fragment, ShaderSource::FRAGMENT),
m_vertex(vertex, ShaderSource::VERTEX),
m_success(),
m_info(),
m_loaded(false)
{}

YAML::Node sw::Shader::save() const
{
    YAML::Node node;

    node["fragment"] = m_fragmentPath;
    node["vertex"] = m_vertexPath;
    return node;
}

void sw::Shader::load(YAML::Node node)
{
    setShaderSource(node["fragment"].as<std::string>(), sw::ShaderSource::FRAGMENT);
    setShaderSource(node["vertex"].as<std::string>(), sw::ShaderSource::VERTEX);
}

sw::Shader::~Shader()
{
    glDeleteProgram(m_id);
}

const unsigned int &sw::Shader::getId() const noexcept
{
    return (m_id);
}

const bool sw::Shader::isLoaded() const noexcept
{
    return (m_loaded);
}

void sw::Shader::useShader() const
{
    glUseProgram(getId());
}

sw::Shader &sw::Shader::setShaderSource(std::string source, sw::ShaderSource::ShaderType type)
{
    if (type == sw::ShaderSource::FRAGMENT) {
        glDetachShader(m_id, m_fragment.getId());
        m_fragment = sw::ShaderSource(source, type);
        glAttachShader(m_id, m_fragment.getId());
        m_fragmentPath = source;
    }
    else {
        glDetachShader(m_id, m_vertex.getId());
        m_vertex = sw::ShaderSource(source, type);
        glAttachShader(m_id, m_vertex.getId());
        m_vertexPath = source;
    }
    glLinkProgram(m_id);
    glGetProgramiv(m_id, GL_LINK_STATUS, &m_success);
    if (!m_success) {
        glGetProgramInfoLog(m_id, 512, nullptr, m_info);
        std::cerr << "ERROR: shader linking [" << source << "]: " << m_info << std::endl;
    }
    return (*this);
}

int sw::Shader::getUniLocation(std::string &name) const
{
    int result = glGetUniformLocation(m_id, name.c_str());

    if (result == -1)
        throw sw::Error("Uniform shader variable not found: " + name, "");
    return (result);
}

void sw::Shader::setUniBool(std::string varName, bool &value) const
{
    glUniform1i(getUniLocation(varName), value);
}

void sw::Shader::setUniInt(std::string varName, int value) const
{
    glUniform1i(getUniLocation(varName), value);
}

void sw::Shader::setUniFloat(std::string varName, float value) const
{
    glUniform1f(getUniLocation(varName), value);
}

void sw::Shader::setUniMat4(std::string varName, const glm::mat4 &matrix) const
{
    glUniformMatrix4fv(getUniLocation(varName), 1, GL_FALSE, glm::value_ptr(matrix));
}

void sw::Shader::setUniFloat3(std::string varName, const float &v1, const float &v2, const float &v3) const
{
    glUniform3f(getUniLocation(varName), v1, v2, v3);
}

void sw::Shader::setUniFloat3(std::string varName, const sw::Vector3f vector) const
{
    glUniform3f(getUniLocation(varName), vector.x, vector.y, vector.z);
}

void sw::Shader::createShader()
{
    m_id = glCreateProgram();
    m_fragment.compile();
    m_vertex.compile();
    glAttachShader(m_id, m_fragment.getId());
    glAttachShader(m_id, m_vertex.getId());
    glLinkProgram(m_id);
    glGetProgramiv(m_id, GL_LINK_STATUS, &m_success);
    if (!m_success) {
        glGetProgramInfoLog(m_id, 512, nullptr, m_info);
        throw sw::Error("ERROR: shader linking: " + std::string(m_info), "");
    }
}

void sw::Shader::update()
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