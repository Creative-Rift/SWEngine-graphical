/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Resources.cpp
** Description: [CHANGE]
*/

#include "resources/OpenResources.hpp"
#include "SW/Engine.hpp"
#include "dependencies/glad/glad.h"

#include <iostream>
#include <filesystem>
#include <memory>

sw::OpenResources::~OpenResources()
{
}

void sw::OpenResources::loadResources()
{
    sw::Speech::Info("Loading all resources...", "1227");
    try {
        loadTextures();
        sw::Speech::Info("Resources loaded successfully!", "2227");
    } catch (sw::Error& error) {
        sw::Speech::Error(error.getMessage(), error.getCode());
    }
}

void sw::OpenResources::loadTextures()
{
    for (auto &[name, path] : m_ntx) {
        m_ntext.emplace(name, std::make_shared<Texture>(path));
    }
    if (m_ntext.empty())
        sw::Speech::Warning("No Texture was loaded.", "3720");   
}

void sw::OpenResources::addNeededResource(const std::string& name, const std::string& path, const std::string&)
{
    if (m_ntx.find(name) == m_ntx.end())
        m_ntx.emplace(name, path);
}

void sw::OpenResources::unloadResources()
{
    for(auto &itr = m_ntext.begin(); itr != m_ntext.end(); itr++)
    {
        delete (itr->second);
    }
    m_ntext.clear();
}
