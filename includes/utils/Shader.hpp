/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Shader.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_SHADER_HPP
#define SWENGINE_OPENGLMODULE_SHADER_HPP

#include "ShaderSource.hpp"

namespace sw
{
    class Shader
    {
        private:
            unsigned int m_id;
            ShaderSource m_fragment;
            ShaderSource m_vertex;
            int m_success;
            char m_info[512];
        public:
            Shader();
            ~Shader();
            [[nodiscard]] const unsigned int& getId() const noexcept;
    }; // class Shader
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_SHADER_HPP
