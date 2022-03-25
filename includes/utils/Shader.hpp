/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Shader.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_SHADER_HPP
#define SWENGINE_OPENGLMODULE_SHADER_HPP

#include "dependencies/glm/glm.hpp"
#include "dependencies/glm/gtc/type_ptr.hpp"

#include "OpenGLModule_Config.hpp"
#include "ShaderSource.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Shader
    {
        private:
            unsigned int m_id;
            ShaderSource m_fragment;
            ShaderSource m_vertex;
            int m_success;
            char m_info[512];

            int getUniLocation(std::string& name) const;
        public:
            Shader();
            Shader(std::string fragment, std::string vertex);
            ~Shader();
            [[nodiscard]] const unsigned int& getId() const noexcept;
            void useShader() const;
            void setUniBool(std::string varName, bool& value) const;
            void setUniInt(std::string varName, int& value) const;
            void setUniFloat(std::string varName, float& value) const;
            void setUniMat4(std::string varName, const glm::mat4& matrix) const;
            void setUniFloat3(std::string varName, const float &v1, const float &v2, const float &v3) const;
            // TODO Add more setUniform
    }; // class Shader
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_SHADER_HPP
