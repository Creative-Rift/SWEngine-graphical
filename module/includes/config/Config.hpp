/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Config.h
** Description: [CHANGE]
*/

#ifndef SHIPWRECK_CONFIG_HPP
#define SHIPWRECK_CONFIG_HPP

#include "yaml-cpp/yaml.h"
#include "OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Config
    {
        public:
            static std::string m_configFile;
            static YAML::Node m_config;
            static void SetupConfig();
            static void ReloadConfig();
            static void UpdateConfigFile();
            static YAML::Node& GetConfig();
    };
}


#endif //SHIPWRECK_CONFIG_HPP
