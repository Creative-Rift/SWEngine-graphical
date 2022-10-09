/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Vertex.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_VERTEX_HPP
#define SWENGINE_OPENGLMODULE_VERTEX_HPP

#include <iostream>
#include "Vector3.hpp"
#include "Color.hpp"
#include "OpenGLModule_Config.hpp"
#include "../utils/Vector2.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Vertex
    {
    public:
        Vector3f position;
        Color color;
        Vector2f textureCoord;
        Vector3f normal;
        Vector3f bitangent;
        Vector3f tangent;

            Vertex();
            ~Vertex();
            explicit Vertex(Vector3f& position);
            Vertex(Vector3f& position, Vector2f& textureCoord);
            Vertex(Vector3f& position, Color& color);
            Vertex(Vector3f& position, Vector2f& textureCoord, Color& color);
    }; // class Vertex

    #include "Vertex.inl"
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_VERTEX_HPP
