/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2023
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/

#include "gameObject/GameObject.hpp"
#include "components/ui/TextInput.hpp"

sw::TextInput::TextInput(sw::GameObject &gameObject, std::string defaultValue) :
Component(gameObject),
m_text(),
m_selected(false),
m_value(defaultValue),
m_textPos(0, 0)
{
    gameObject.scene().eventManager["Start"].subscribe(m_gameObject.name(), this,  &sw::TextInput::start);
}

void sw::TextInput::start()
{
    m_text.emplace(m_gameObject.createComponent<sw::Text>("TextManager"));
    m_text.value().setText(m_value).setPosition(m_textPos.x, m_textPos.y).setFont("PixelFont");
}

bool sw::TextInput::isSelected() const
{
    return m_selected;
}

const std::string &sw::TextInput::getValue() const
{
    return m_value;
}
