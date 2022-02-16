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
m_ebo{},
m_array{},
m_indices{0, 1, 3, 1, 2, 3}
{
    sw::Vector3f a{0.5f, 0.5f, 0.0f};
    sw::Vector3f b{0.5f, -0.5f, 0.0f};
    sw::Vector3f c{-0.5f, -0.5f, 0.0f};
    sw::Vector3f d{-0.5f, 0.5f, 0.0f};
    sw::Color c1{1, 0, 0};
    sw::Color c2{0, 1, 0};
    sw::Color c3{0, 0, 1};
    m_array.emplace_back(sw::Vertex{a, c1});
    m_array.emplace_back(sw::Vertex{b, c2});
    m_array.emplace_back(sw::Vertex{c, c1});
    m_array.emplace_back(sw::Vertex{d, c3});
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    update();
}

sw::VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
}

void sw::VertexArray::update()
{
    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(sw::Vertex) * m_array.size(), m_array.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_STATIC_DRAW);

    // Vertex position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), reinterpret_cast<void *>(0));

    // Vertex Color
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), reinterpret_cast<void *>(3 * sizeof(float)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

const unsigned int& sw::VertexArray::getVAO() const noexcept
{
    return (m_vao);
}

const unsigned int& sw::VertexArray::getEBO() const noexcept
{
    return (m_ebo);
}