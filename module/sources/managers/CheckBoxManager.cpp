//
// Created by guill on 15/08/2023.
//

#include "CheckBoxManager.hpp"
#include "window/Window.hpp"

void sw::CheckBoxManager::onUpdate()
{
    sw::Vector2f mousePos = sw::getMousePosition();

    for (auto&[_, obj]: m_components) {
        sw::Vector3f pos = obj->gameObject().transform().getGlobalPosition();
        auto width = obj->m_sprite.value().getMaterial().texture->getWidth();
        auto height = obj->m_sprite.value().getMaterial().texture->getHeight();

        if (mousePos.x >= pos.x + obj->m_hitBox.left &&
            mousePos.x < pos.x + width * obj->gameObject().transform().getScale().x + obj->m_hitBox.width &&
            mousePos.y >= pos.y + obj->m_hitBox.top &&
            mousePos.y < pos.y + height * obj->gameObject().transform().getScale().y + obj->m_hitBox.height) {
            obj->m_sprite.value().setColor(sw::Color{1.0f, 1.0f, 1.0f});
            obj->m_hover = true;
            if (sw::isMouseButtonPressed(sw::MouseBtn::Button_left)) {
                obj->m_value = !obj->m_value;
                obj->m_sprite.value().setTexture(obj->m_value ? obj->m_spriteOn : obj->m_spriteOff);
            }
        } else {
            obj->m_sprite.value().setColor(sw::Color{100.0f / 255.0f, 100.0f / 255.0f, 100.0f / 255.0f});
            obj->m_hover = false;
        }
    }
}
