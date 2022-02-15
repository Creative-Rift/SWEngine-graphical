/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: VertexArray.cpp
** Description: [CHANGE]
*/

#include "dependencies/glad/glad.h"

#include "utils/VertexArray.hpp"

sw::VertexArray::VertexArray() :
m_vbo{0},
m_vao{0},
m_array{},
vertices{
   -0.5f, -0.5f, 0.0f,  // bottom left
    0.5f, -0.5f, 0.0f,  // bottom right
   0.0f,  0.5f, 0.0f   // top left
}
{
    sw::Vector3f a{-0.5f, -0.5f, 0.0f};
    sw::Vector3f b{0.5f, -0.5f, 0.0f};
    sw::Vector3f c{0.0f, 0.5f, 0.0f};
    m_array.emplace_back(sw::Vertex{a});
    m_array.emplace_back(sw::Vertex{b});
    m_array.emplace_back(sw::Vertex{c});
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);

    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    update();
}

sw::VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
}

void sw::VertexArray::update()
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(sw::Vertex) * m_array.size(), m_array.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), reinterpret_cast<void *>(0));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

const unsigned int& sw::VertexArray::getVAO() const noexcept
{
    return (m_vao);
}