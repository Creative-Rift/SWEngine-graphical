/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Material.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_MATERIAL_HPP
#define SWENGINE_OPENGLMODULE_MATERIAL_HPP

#include "yaml-cpp/yaml.h"
#include "OpenGLModule_Config.hpp"
#include "resources/OpenResources.hpp"
#include "utils/Shader.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Material
    {
        public:
            std::string m_name;
            std::shared_ptr<Texture> texture;
            Shader shader;

            YAML::Node save() const;
            void load(YAML::Node node);
            Material();
            explicit Material(std::shared_ptr<Texture>& texture);
            explicit Material(std::string textureName);
            Material(std::shared_ptr<Texture>& texture, Shader& shader);
            Material& setShader(Shader shader);
            Material& setTexture(std::string textureName);
    }; // class Material
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_MATERIAL_HPP
