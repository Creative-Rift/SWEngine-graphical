/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2023
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/


#include "components/ui/Button.hpp"
#include "gameObject/GameObject.hpp"
#include "components/Components.hpp"
#include "Window.hpp"

sw::Button::Button(sw::GameObject &gameObject) :
Component(gameObject)
{
    gameObject.scene().eventManager["Start"].subscribe(m_gameObject.name(), this,  &sw::Button::start);
}

void sw::Button::start()
{
    m_sprite.emplace(m_gameObject.createComponent<sw::Sprite>("SpriteManager").setTexture(m_textureName));
    m_gameObject.transform().move(m_position);
    m_gameObject.transform().setScale(m_scale.x, m_scale.y, 0);
    m_text.emplace(m_gameObject.createComponent<sw::Text>("TextManager"));
    m_text.value().setText(m_buttonTitle).setPosition(m_position.x + m_txtPosition.x, sw::Window::GetSize().y - m_txtPosition.y - 40 - m_position.y).setFont("PixelFont");
    m_audio.emplace(m_gameObject.createComponent<sw::AudioSource>("AudioManager"));
    m_audio.value().addAudio("UI_Switch_1").addAudio("UI_Switch_2").addAudio("UI_Switch_3").addAudio("UI_Select");
}

sw::AudioSource &sw::Button::getAudio()
{
    return m_audio.value();
}

sw::Text &sw::Button::getText()
{
    return m_text.value();
}
