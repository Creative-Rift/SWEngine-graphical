/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Vertex.inl
** Description: [CHANGE]
*/

inline Vertex::Vertex() :
m_position{0, 0, 0},
m_color(1.0f, 1.0f, 1.0f)
//m_textureCoord(0, 0),
{}

inline Vertex::Vertex(Vector3f& position) :
m_position(position.x, position.y, position.z),
m_color(1.0f, 1.0f, 1.0f, 1.0f)
//m_textureCoord(0, 0),
{}

//constexpr Vertex::Vertex(Vector3f& position, Vector2f& textureCoord) :
//m_position(position.x, position.y, position.z)/*,
//m_textureCoord(textureCoord.x, textureCoord.y),
//Color(255, 255, 255)*/
//{}

inline Vertex::Vertex(Vector3f& position, Color& color) :
m_position(position.x, position.y, position.z),
m_color(color.r, color.g, color.b, color.a)
//m_textureCoord(0, 0),
{}

//constexpr Vertex::Vertex(Vector3f& position, Vector2f& textureCoord, Color& color) :
//m_position(position.x, position.y, position.z),
//m_textureCoord(textureCoord.x, textureCoord.y),
//Color(color.r, color.g, color.b, color.a)
//{}