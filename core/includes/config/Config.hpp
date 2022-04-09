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


namespace sw
{
    class Config
    {
        public:
            static std::string m_configFile;
            static YAML::Node m_config;
            static void SetupConfig();
            static void ReloadConfig();
            static void UpdateConfigFile();
    };
}


#endif //SHIPWRECK_CONFIG_HPP
