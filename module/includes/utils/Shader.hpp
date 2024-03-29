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
#include "yaml-cpp/yaml.h"

#include "OpenGLModule_Config.hpp"
#include "ShaderSource.hpp"
#include "utils/Vector3.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Shader
    {
        private:
            unsigned int m_id;
            ShaderSource m_fragment;
            ShaderSource m_vertex;
            std::string m_fragmentPath;
            std::string m_vertexPath;
            int m_success;
            char m_info[512];
            bool m_loaded;

            int getUniLocation(std::string& name) const;
        public:
            void createShader();

            YAML::Node save() const;
            void load(YAML::Node node);

            Shader( Shader const& ) = delete;
            Shader( Shader&& ) = delete;

            Shader();
            Shader(std::string fragment, std::string vertex);
            ~Shader();

            Shader& operator=(const Shader& other) = delete;
            Shader& operator=( Shader&& ) = delete;

            Shader &setShaderSource(std::string source, ShaderSource::ShaderType type);

            [[nodiscard]] const unsigned int& getId() const noexcept;
            [[nodiscard]] const bool isLoaded() const noexcept;
            void useShader() const;
            void setUniBool(std::string varName, bool& value) const;
            void setUniInt(std::string varName, int value) const;
            void setUniFloat(std::string varName, float value) const;
            void setUniMat4(std::string varName, const glm::mat4& matrix) const;
            void setUniFloat3(std::string varName, const float &v1, const float &v2, const float &v3) const;
            void setUniFloat3(std::string varName, const Vector3f vector) const;

            void update();
    }; // class Shader
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_SHADER_HPP
