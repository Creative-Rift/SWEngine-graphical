/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Shader.cpp
** Description: [CHANGE]
*/

#include <fstream>
#include <sstream>
#include <iostream>

#include "SW/utils/Speech.hpp"

#include "dependencies/glad/glad.h"
#include "utils/ShaderSource.hpp"
#include "SW/Errors.hpp"

sw::ShaderSource::ShaderSource(std::string&& shaderFile, ShaderType type) :
m_shaderContent{},
m_id{},
m_success{},
m_info{}
{
    std::fstream file(shaderFile);
    std::stringstream ss;

    if (!file.is_open())
        throw sw::Error("File " + shaderFile + " cannot be open", "");
    ss << file.rdbuf();
    m_shaderContent = ss.rdbuf()->str();
    file.close();
    m_id = glCreateShader(type);
    compile();
}

void sw::ShaderSource::compile()
{
    char *str = m_shaderContent.data();

    glShaderSource(m_id, 1, &str, nullptr);
    glCompileShader(m_id);
    glGetShaderiv(m_id, GL_COMPILE_STATUS, &m_success);
    if (!m_success) {
        glGetShaderInfoLog(m_id, 512, nullptr, m_info);
        std::cerr << "Error Shader couldn't compile: " << m_info << std::endl;
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