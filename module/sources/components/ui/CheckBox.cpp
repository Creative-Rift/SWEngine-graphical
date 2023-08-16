//
// Created by guill on 15/08/2023.
//

#include "components/ui/CheckBox.hpp"
#include "gameObject/GameObject.hpp"

sw::CheckBox::CheckBox(sw::GameObject &gameObject, std::string spriteOn, std::string spriteOff, bool defaultValue) :
sw::Component(gameObject),
m_value(defaultValue),
m_spriteOff(spriteOff),
m_spriteOn(spriteOn),
m_hitBox(0, 0, 0, 0)
{
    gameObject.scene().eventManager["Start"].subscribe(m_gameObject.name(), this,  &CheckBox::start);
}

void sw::CheckBox::start()
{
    m_sprite.emplace(m_gameObject.createComponent<sw::Sprite>("SpriteManager").setTexture(m_value ? m_spriteOn : m_spriteOff));
    m_gameObject.transform().setScale(m_scale.x, m_scale.y, 0);
}

bool sw::CheckBox::getValue() const
{
    return m_value;
}
