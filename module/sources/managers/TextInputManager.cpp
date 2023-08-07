/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2023
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/

#include "Window.hpp"

#include "TextInputManager.hpp"

YAML::Node sw::TextInputManager::save() const
{
    return AManager::save();
}

void sw::TextInputManager::onLoad(YAML::Node &node)
{
    AManager::onLoad(node);
}

void sw::TextInputManager::onUpdate()
{
    sw::Vector2f mousePos = sw::getMousePosition();

    for (auto &[_, obj]: m_components) {
        obj->m_text.value().setColor(sw::WhiteColor);
        if (mousePos.x >= obj->m_textPos.x &&
            mousePos.x < obj->m_textPos.x + 200 &&
            sw::Window::GetSize().y - mousePos.y >= obj->m_textPos.y &&
            sw::Window::GetSize().y - mousePos.y < obj->m_textPos.y + 50 &&
            !obj->m_selected)
        {
            obj->m_text.value().setColor(sw::RedColor);
            if (sw::isMouseButtonReleased(sw::MouseBtn::Button_left))
                obj->m_selected = true;
        } else {
            if (sw::isMouseButtonReleased(sw::MouseBtn::Button_left))
                obj->m_selected = false;
        }
        if (obj->m_selected)
                obj->m_text.value().setColor(sw::GreenColor);
        if (obj->m_selected)
            keyBoardHandler(obj);
    }
}

void sw::TextInputManager::keyBoardHandler(std::shared_ptr<sw::TextInput> obj)
{
    sw::Keyboard key = sw::GetKeyPressed();
    int shift = sw::isKeyDown(sw::LSHIFT) || sw::isKeyDown(sw::RSHIFT) ? 0 : 32;
    if (key != sw::UNKNOWN)
        obj->m_value.push_back((char)key + (std::isalpha(key) ? shift : 0));
    if (sw::isKeyPressed(sw::BACKSPACE) && obj->m_value.length() > 0)
        obj->m_value.pop_back();
    obj->m_text.value().setText(obj->m_value);
}
