/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Material.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_MATERIAL_HPP
#define SWENGINE_OPENGLMODULE_MATERIAL_HPP

#include "resources/OpenResources.hpp"
#include "utils/Shader.hpp"

#include "OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Material
    {
        public:
            std::shared_ptr<sw::Texture> texture;
            Shader shader;

            Material();
            explicit Material(std::shared_ptr<sw::Texture>& texture);
            explicit Material(std::string textureName);
            Material(std::shared_ptr<sw::Texture>& texture, Shader& shader);
    };
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_MATERIAL_HPP
