/*
** ShipWreck Engine , 2022
** Primitive.hpp
*/

#ifndef SHIPWRECK_ENGINE_PRIMITIVE_HPP
#define SHIPWRECK_ENGINE_PRIMITIVE_HPP

#include "base/Component.hpp"
#include "utils/Shader.hpp"
#include "utils/Vertex.hpp"
#include "OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Primitive : public Component
    {
    public:
        explicit Primitive(GameObject& gameObject);
        ~Primitive();
        unsigned int m_vbo;
        unsigned int m_vao;
        unsigned int m_ebo;
        ::std::vector<Vertex> m_array;
        std::shared_ptr<Shader> m_shader;

        void update();
    }; //class Primitive
} // namespace sw

#endif //SHIPWRECK_ENGINE_PRIMITIVE_HPP
