/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: VertexArray.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_TEST_VERTEXARRAY_HPP
#define SWENGINE_OPENGLMODULE_TEST_VERTEXARRAY_HPP

#include <vector>
#include "Vertex.hpp"

namespace sw
{
    class VertexArray
    {
        private:
            unsigned int m_vbo;
            unsigned int m_vao;
            ::std::vector<Vertex> m_array;
            float vertices[9];
        public:
            VertexArray();
            ~VertexArray();
            void update();
            [[nodiscard]] const unsigned int& getVAO() const noexcept;
    }; // class VertexArray
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_TEST_VERTEXARRAY_HPP
