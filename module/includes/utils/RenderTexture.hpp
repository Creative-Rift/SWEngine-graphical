/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: RenderTexture.cpp
** Description: [CHANGE]
*/


#ifndef SHIPWRECK_ENGINE_RENDERTEXTURE_HPP
#define SHIPWRECK_ENGINE_RENDERTEXTURE_HPP

#include "dependencies/glad/glad.h"
#include "resources/OpenResources.hpp"
namespace sw
{
    class RenderTexture
    {
        private:
            std::string m_name;
            GLuint m_frameBufferId;
            Texture m_texture;

            void CreateRenderTexture();
        public:
            RenderTexture();
            explicit RenderTexture(std::string name);
    }; // class RenderTexture
} // namespace sw

#endif //SHIPWRECK_ENGINE_RENDERTEXTURE_HPP
