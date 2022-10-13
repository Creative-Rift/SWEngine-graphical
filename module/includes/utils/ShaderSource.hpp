/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Shader.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_TEST_SHADER_HPP
#define SWENGINE_OPENGLMODULE_TEST_SHADER_HPP

#include <string>

#include "OpenGLModule_Config.hpp"
#include "dependencies/glad/glad.h"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT ShaderSource
    {
        public:
            enum ShaderType {
                VERTEX = GL_VERTEX_SHADER,
                FRAGMENT = GL_FRAGMENT_SHADER
            };

            explicit ShaderSource(std::string shaderFile, ShaderType type);
            void compile();
            [[nodiscard]] const std::string& getShader() const noexcept;
            [[nodiscard]] const unsigned int& getId() const noexcept;
        private:
            std::string m_shaderContent;
            unsigned int m_id;
            int m_success;
            char m_info[512];
            ShaderType m_type;
    }; // class ShaderSource
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_TEST_SHADER_HPP
