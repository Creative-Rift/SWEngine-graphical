#include "components/Text.hpp"
#include "OpenGLModule.hpp"

sw::Text::Text(sw::GameObject& gameObject) :
sw::Component(gameObject),
m_text(std::wstring(L"Hello world")),
m_fontName("DefaultFont"),
m_size(48),
m_font(sw::OpenResources::m_nfont["DefaultFont"]),
m_color(),
m_shader(sw::OpenResources::m_nshader["text"]),
m_pos(),
m_scale(1)
{}

sw::Text &sw::Text::setText(std::wstring text)
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

sw::Text &sw::Text::setPosition(float xpos, float ypos)
{
    m_pos.first = xpos;
    m_pos.second = ypos;
    return (*this);
}

sw::Text &sw::Text::setSize(float scale)
{
    m_scale = scale;
    return (*this);
}

sw::Text &sw::Text::setFont(std::string name)
{
    m_font = sw::OpenResources::m_nfont[name];
    return (*this);
}

sw::Text &sw::Text::setColor(sw::Color color)
{
    m_color = color;
    return (*this);
}

const std::shared_ptr<sw::Shader> sw::Text::getShader() const noexcept
{
    return (m_shader);
}

const sw::Color &sw::Text::getColor() const noexcept
{
    return (m_color);
}

const std::wstring &sw::Text::getText() const noexcept
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
    return (m_scale);
}

/*
sw::Text &sw::Text::setNumberChar(unsigned int nbr)
{
    m_nbrDisplayedChar = nbr;
    return (*this);
}
*/
YAML::Node sw::Text::save() const
{
    YAML::Node node;

    //node["entity_name"] = name();
    //node["text"] = m_text;
    //node["shader"] = m_shader.save();
    //node["color"] = m_color.save();
    //node["posx"] = m_pos.first;
    //node["posy"] = m_pos.second;
    //node["scale"] = scale;
    //node["font"] = m_fontName;

    return (node);
}