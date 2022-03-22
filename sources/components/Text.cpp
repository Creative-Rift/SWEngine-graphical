#include "components/Text.hpp"
#include "resources/OpenResources.hpp"

sw::Text::Text(sw::Entity& entityRef) :
sw::Component(entityRef),
m_text(std::string("Hello world")),
m_size(48),
m_font(sw::OpenResources::m_nfont["DefaultFont"]),
m_color(),
m_shader("resources/shaders/fragment_font.glsl", "resources/shaders/vertex_font.glsl"),
m_pos(),
scale(1)
{}

sw::Text &sw::Text::setText(std::string &text)
{
    m_text = text;
    return (*this);
}

/*
sw::Text &sw::Text::setFontSize(unsigned int size)
{
    m_size = size;
    return (*this);
}
*/

sw::Text &sw::Text::setPosition(float &xpos, float &ypos)
{
    m_pos.first = xpos;
    m_pos.second = ypos;
    return (*this);
}

sw::Text &sw::Text::setFont(std::string& name)
{
    m_font = sw::OpenResources::m_nfont[name];
    return (*this);
}

sw::Text &sw::Text::setColor(sw::Color &color)
{
    m_color = color;
    return (*this);
}

const sw::Shader &sw::Text::getShader() const noexcept
{
    return (m_shader);
}

const sw::Color &sw::Text::getColor() const noexcept
{
    return (m_color);
}

const std::string &sw::Text::getText() const noexcept
{
    return (m_text);
}

const std::shared_ptr<sw::Font>& sw::Text::getFont() const noexcept
{
    return (m_font);
}

const std::pair<float, float>& sw::Text::getPos() const noexcept
{
    return (m_pos);
}

const float& sw::Text::getScale() const noexcept
{
    return (scale);
}

/*
sw::Text &sw::Text::setNumberChar(unsigned int nbr)
{
    m_nbrDisplayedChar = nbr;
    return (*this);
}*/