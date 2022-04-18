/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Config.cpp
** Description: [CHANGE]
*/

#include <fstream>

#include "utils/Speech.hpp"
#include "config/Config.hpp"

YAML::Node sw::Config::m_config;
std::string sw::Config::m_configFile;

void sw::Config::SetupConfig()
{
    m_configFile = "./config.yaml";
    m_config = YAML::LoadFile(m_configFile);

    sw::Speech::ConfigSpeech();
}

void sw::Config::ReloadConfig()
{
    SetupConfig();
}

void sw::Config::UpdateConfigFile()
{
    std::ofstream out(m_configFile);

    out << m_config;
}