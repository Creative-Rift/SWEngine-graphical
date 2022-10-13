/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Shader.cpp
** Description: [CHANGE]
*/

#include <fstream>
#include <sstream>

#include "utils/Speech.hpp"

#include "dependencies/glad/glad.h"
#include "utils/ShaderSource.hpp"
#include "exception/Error.hpp"

sw::ShaderSource::ShaderSource(std::string shaderFile, ShaderType type) :
m_shaderContent{},
m_id{0},
m_success{},
m_info{},
m_type{type}
{
    std::fstream file(shaderFile);
    std::stringstream ss;

    if (!file.is_open())
        throw sw::Error("File " + shaderFile + " cannot be open", "");
    ss << file.rdbuf();
    m_shaderContent = ss.rdbuf()->str();
    file.close();
}

void sw::ShaderSource::compile()
{
    char *str = m_shaderContent.data();

    if (m_id == 0)
        m_id = glCreateShader(m_type);
    glShaderSource(m_id, 1, &str, nullptr);
    glCompileShader(m_id);
    glGetShaderiv(m_id, GL_COMPILE_STATUS, &m_success);
    if (!m_success) {
        glGetShaderInfoLog(m_id, 512, nullptr, m_info);
        throw sw::Error("Error Shader couldn't compile: " + std::string(m_info), "");
    }
}

const std::string &sw::ShaderSource::getShader() const noexcept
{
    return (m_shaderContent);
}

const unsigned int &sw::ShaderSource::getId() const noexcept
{
    return (m_id);
}