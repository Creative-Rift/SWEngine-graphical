/*
** ShipWreck Engine , 2022
** Mesh.hpp
*/

#ifndef SHIPWRECK_ENGINE_MESH_HPP
#define SHIPWRECK_ENGINE_MESH_HPP

#include <vector>

#include "utils/Vertex.hpp"
#include "utils/Shader.hpp"

namespace sw
{
    class Texture;

    class SW_GRAPH_MODULE_EXPORT Mesh{
    public:
        // In Vertex Array
        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        //End
        ~Mesh();

        std::vector<std::shared_ptr<Texture>> m_texture;

        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<std::shared_ptr<Texture>> materials);

    private:

        void setupMesh();

    };
}

#endif //SHIPWRECK_ENGINE_MESH_HPP
